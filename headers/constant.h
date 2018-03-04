#ifndef CONSTANT
    #define CONSTANT

    #include <stdio.h>
    #include <stdlib.h>
    #include <SDL/SDL.h>
    #include <time.h>


    // Dimentions
    #define NBR_CASE_X 30
    #define NBR_CASE_Y 20

    // Constant for the field
    #define NORMAL 0
    #define FOREST 1
    #define RIVER 2

    // Constant for the Characters
    #define EMPTY 0
    #define SCOUT 1
    #define INFANTRYMAN 2
    #define SHOCK_TROOPS 3
    #define FLAG 4

    // PA per Characters
    #define PA_SCOUT 5
    #define PA_INFANTRYMAN 3
    #define PA_SHOCK 2

    // Basic constants
    #define TRUE 1
    #define FALSE 0

    // Structure of a charachter in a team
    typedef struct Player
    {
        int type;
        int flag;
        int actionPoint;
        SDL_Rect position;
    } Player;

    // Structure of the charachter on the map
    typedef struct Character
    {
        int team;
        int type;
        int flag;
    } Character;

    // Structure of a case of field
    typedef struct Square
    {
        int field;
        Character pawn;
        int visible_red;
        int visible_blue;
    }Square;


#endif
