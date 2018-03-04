#include "../headers/game.h"
#include "../headers/tools.h"

void game(SDL_Surface *screen, Square **map, Player **players)
{
    int win = FALSE;
    int team_number;
    //initialisation des positions
    init_position(map, players, NBR_OF_PLAYER, NBR_MEMBER);

    do{
        for(team_number = 0; team_number < NBR_OF_PLAYER; team_number++)
        {
            display_infobar(screen, players[team_number], team_number + 1);
            win = game_turn(map, players, team_number);
        }
    } while(!win);

    display_field(screen, map);
    display_infobar(screen, players[0], 1);
}


int game_turn(Square **map, Player **players, int team_number)
{
    int i;

    for(i = 0; i < NBR_MEMBER; i++)
    {

    }

    return TRUE;
}

void move_pawn(Player** players, Square** map, SDL_Rect prev_loc, SDL_Rect actual_loc)
{
    int team, id;
    team = map[prev_loc.y][prev_loc.x].pawn.team;
    id = map[prev_loc.y][prev_loc.x].pawn.id;
    players[team][id].position.x = actual_loc.x;
    players[team][id].position.y = actual_loc.y;

    map[actual_loc.y][actual_loc.x].pawn.id = map[prev_loc.y][prev_loc.x].pawn.id;
    map[actual_loc.y][actual_loc.x].pawn.team = map[prev_loc.y][prev_loc.x].pawn.team;
    map[actual_loc.y][actual_loc.x].pawn.type = map[prev_loc.y][prev_loc.x].pawn.type;

    map[prev_loc.y][prev_loc.x].pawn.type = EMPTY;



}
