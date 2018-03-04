#ifndef GAME
    #define GAME

    #include "constant.h"
    #include "display.h"
    #include "tools.h"

    #define NBR_OF_PLAYER 2

    #define NBR_SCOUT 4
    #define NBR_INFANTRYMAN 2
    #define NBR_SHOCK 1
    #define NBR_MEMBER NBR_SCOUT + NBR_INFANTRYMAN + NBR_SHOCK

    // Main game fonction
    void game(SDL_Surface *screen, Square **map, Player **players);

    // Move a pawn to an other position
    void move_pawn(Player** players, Square** map, SDL_Rect prev_loc, SDL_Rect actual_loc);


#endif
