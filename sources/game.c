#include "../headers/game.h"
#include "../headers/tools.h"

void game(SDL_Surface *screen, Square **map, Player **players)
{
    //initialisation des positions
    init_position(map, players, NBR_OF_PLAYER, NBR_MEMBER);

    display_field(screen, map);
    display_infobar(screen, players[0], 1);
}
