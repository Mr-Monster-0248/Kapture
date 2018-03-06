#include "../headers/game.h"
#include "../headers/tools.h"

void game(SDL_Surface *screen, Square **map, Player **players)
{
    int win = FALSE;
    int team_number;
    //initialisation des positions
    init_position(map, players, NBR_OF_PLAYER, NBR_MEMBER);

    display_field(screen, map);

    do{
        for(team_number = 0; team_number < NBR_OF_PLAYER; team_number++)
        {
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
        while(players[team_number - 1][i].actionPoint != 0 && event.type != SDL_QUIT)
        {
            display_cursor(screen, players[team_number - 1][i]);
            fprintf(stderr, "%d PA left for player %d\n", players[team_number - 1][i].actionPoint, i);
            fprintf(stderr, "wait key\n");
            SDL_WaitEvent(&event);
            fprintf(stderr, "key pressed\n");
            switch (event.type)
            {
                case SDL_QUIT:
                    players[team_number - 1][i].actionPoint = 0;
                    print_log(screen, "exit turn");
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

            if(check_move(map, move))
            {
                move_pawn(i, players, map, players[team_number - 1][i].position, move);
                players[team_number - 1][i].actionPoint--;
            }


            display_field(screen, map);
            SDL_Flip(screen);
        }
    }

    return TRUE; // TODO: check the win
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

int check_move(Square **map, SDL_Rect position)
{
    if(position.x < 0 || position.y < 0 || position.x >= NBR_CASE_X || position.y >= NBR_CASE_Y)
    {
        return FALSE;
    }
    else
    {
        if(map[position.y][position.x].pawn.type != EMPTY)
            return FALSE;
        else
            return TRUE;
    }
}
