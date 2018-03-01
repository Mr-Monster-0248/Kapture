#ifndef CONSTANT
    #define CONSTANT

    #include <stdio.h>
    #include <stdlib.h>
    #include <SDL/SDL.h>


    // Dimentions
    #define CASE_HEIGHT 32
    #define CASE_WIDTH CASE_HEIGHT
    #define FIELD_HEIGHT CASE_HEIGHT * 20
    #define FIELD_WIDHT CASE_WIDTH * 30
    #define LOG_HEIGHT CASE_HEIGHT * 5
    #define LOG_WIDTH FIELD_WIDHT
    #define INFOBAR_HEIGHT FIELD_HEIGHT + LOG_HEIGHT
    #define INFOBAR_WIDTH CASE_WIDTH * 10
    #define SCREEN_HEIGHT INFOBAR_HEIGHT
    #define SCREEN_WIDTH FIELD_WIDHT + INFOBAR_WIDTH

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

    // Basic constants
    #define TRUE 1
    #define FALSE 0

#endif
