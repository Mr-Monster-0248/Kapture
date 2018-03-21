#include "../headers/game.h"
#include "../headers/tools.h"

void game(SDL_Surface *screen, Square **map, Player **players)
{
    int win = FALSE;
    int team_number;
    //initialisation des positions
    init_position(map, players, NBR_OF_PLAYER, NBR_MEMBER);

    // display_field(screen, map);

    do{
        for(team_number = 0; team_number < NBR_OF_PLAYER; team_number++)
        {
            give_pa(players);
            display_infobar(screen, players[team_number], team_number + 1);
            win = game_turn(screen, map, players, team_number + 1);
            if(win == 2)
                break;
            print_log(screen, "Next turn");
        }
    } while(!win);


    display_field(screen, map);
    display_infobar(screen, players[0], 1);
}


int game_turn(SDL_Surface *screen, Square **map, Player **players, int team_number)
{
    int i;
    SDL_Event event;
    SDL_Rect move;

    move.x = -1;
    move.y = -1;

    for(i = 0; i < NBR_MEMBER; i++)
    {
        while(players[team_number - 1][i].actionPoint > 0 && event.type != SDL_QUIT)
        {
            display_teamVue(screen, map, players[team_number-1], team_number-1);
            display_cursor(screen, players[team_number - 1][i], i);
            fprintf(stderr, "%d PA left for player %d\n", players[team_number - 1][i].actionPoint, i);
            SDL_WaitEvent(&event);
            switch (event.type)
            {
                case SDL_QUIT:
                    players[team_number - 1][i].actionPoint = 0;
                    print_log(screen, "exit turn");
                    return 2;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) // associate move with the key pressed
                    {
                        case SDLK_w: // z in azerty keymap
                            move.y = players[team_number - 1][i].position.y - 1;
                            move.x = players[team_number - 1][i].position.x;
                            fprintf(stderr, "move pawn %d\n", i);
                            print_log(screen, "move pawn up");
                            break;
                        case SDLK_a: // q in azerty keymap
                            move.y = players[team_number - 1][i].position.y;
                            move.x = players[team_number - 1][i].position.x - 1;
                            fprintf(stderr, "move pawn %d\n", i);
                            print_log(screen, "move pawn left");
                            break;
                        case SDLK_s: // s in azerty keymap
                            move.y = players[team_number - 1][i].position.y + 1;
                            move.x = players[team_number - 1][i].position.x ;
                            fprintf(stderr, "move pawn %d\n", i);
                            print_log(screen, "move pawn down");
                            break;
                        case SDLK_d: // d in azerty keymap
                            move.y = players[team_number - 1][i].position.y;
                            move.x = players[team_number - 1][i].position.x + 1;
                            fprintf(stderr, "move pawn %d\n", i);
                            print_log(screen, "move pawn right");
                            break;
                        case SDLK_q: // a in azerty keymap
                            move.y = players[team_number - 1][i].position.y - 1;
                            move.x = players[team_number - 1][i].position.x - 1;
                            fprintf(stderr, "move pawn %d\n", i);
                            print_log(screen, "move pawn up left");
                            break;
                        case SDLK_e: // e in azerty keymap
                            move.y = players[team_number - 1][i].position.y - 1;
                            move.x = players[team_number - 1][i].position.x + 1;
                            fprintf(stderr, "move pawn %d\n", i);
                            print_log(screen, "move pawn up right");
                            break;
                        case SDLK_x: // x in azerty keymap
                            move.y = players[team_number - 1][i].position.y + 1;
                            move.x = players[team_number - 1][i].position.x + 1;
                            fprintf(stderr, "move pawn %d\n", i);
                            print_log(screen, "move pawn down right");
                            break;
                        case SDLK_z: // w in azerty keymap
                            move.y = players[team_number - 1][i].position.y + 1;
                            move.x = players[team_number - 1][i].position.x - 1;
                            fprintf(stderr, "move pawn %d\n", i);
                            print_log(screen, "move pawn down left");
                            break;
                        case SDLK_ESCAPE:
                            players[team_number - 1][i].actionPoint = 0;
                            print_log(screen, "End turn");
                            return 2;
                            break;
                    }
                    break;
            }

            switch (check_move(map, move, team_number))
            {
                case MOVE:
                    move_pawn(i, players, map, players[team_number - 1][i].position, move);
                    discover_map(map, move, team_number-1);
                    players[team_number - 1][i].actionPoint += remove_pa(map, players[team_number - 1][i]);
                    break;
                case FIGHT:
                    // TODO fight
                    break;
                case TAKE_FLAG:
                    // TODO take the flag
                    break;
                case GIVE_FLAG:
                    // TODO give flag --> win game
                    break;
                default:
                    print_log(screen, "ERROR move not handeled");
            }

            display_infobar(screen, players[team_number], team_number);
            display_teamVue(screen, map, players[team_number-1], team_number-1);
            //display_field(screen, map);
            //SDL_Flip(screen);
        }
    }

    return FALSE; // TODO: check the win
}

void move_pawn(int id, Player** players, Square** map, SDL_Rect prev_loc, SDL_Rect new_loc)
{
    int team;
    team = map[prev_loc.y][prev_loc.x].pawn.team;

    map[prev_loc.y][prev_loc.x].pawn.id = 0;
    map[prev_loc.y][prev_loc.x].pawn.team = 0;
    map[prev_loc.y][prev_loc.x].pawn.type = EMPTY;
    map[prev_loc.y][prev_loc.x].pawn.flag = FALSE;

    map[new_loc.y][new_loc.x].pawn.id = id;
    map[new_loc.y][new_loc.x].pawn.team = team;
    map[new_loc.y][new_loc.x].pawn.type = players[team - 1][id].type;
    map[new_loc.y][new_loc.x].pawn.flag = players[team - 1][id].flag;

    players[team - 1][id].position.x = new_loc.x;
    players[team - 1][id].position.y = new_loc.y;
}

int check_move(Square **map, SDL_Rect position, int team)
{
    if(position.x < 0 || position.y < 0 || position.x >= NBR_CASE_X || position.y >= NBR_CASE_Y)
    {
        return FALSE;
    }
    else
    {
        if(map[position.y][position.x].pawn.type == EMPTY)
            return MOVE;
        else if(map[position.y][position.x].pawn.type == FLAG)
        {
            if(map[position.y][position.x].pawn.team == team)
                return GIVE_FLAG;
            else
                return TAKE_FLAG;
        }
        else
            return FIGHT;
    }
}


int remove_pa(Square **map, Player player)
{
    if(map[player.position.y][player.position.x].field == NORMAL)
        return -1;
    else if(map[player.position.y][player.position.x].field == FOREST)
        return -2;
    else
        return -10; // just to remove every PA
}

void give_pa(Player **players)
{
    int i, j;
    for(i = 0; i < NBR_OF_PLAYER; i++)
    {
        for(j = 0; j < NBR_MEMBER; j++)
        {
            if(players[i][j].type == SCOUT)
                players[i][j].actionPoint = PA_SCOUT;
            else if(players[i][j].type == INFANTRYMAN)
                players[i][j].actionPoint = PA_INFANTRYMAN;
            else
                players[i][j].actionPoint = PA_SHOCK;
        }
    }
}
