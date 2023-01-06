//
// Created by Thibault Lepez on 06/01/2023.
//

#ifndef KAPTURE_2_DISPLAY_H
#define KAPTURE_2_DISPLAY_H

#include "constant.h"

// ===== Dimentions in pixels =====

// Full window size
#define SCREEN_HEIGHT 800
#define SCREEN_WIDTH 1280

// Square of the field
#define SQUARE_HEIGHT 32
#define SQUARE_WIDTH SQUARE_HEIGHT

// Window where is display the visible field
#define FIELD_HEIGHT 640
#define FIELD_WIDHT 960

// Window where the log will be displayed
#define LOG_HEIGHT 160
#define LOG_WIDTH FIELD_WIDHT

// Window where the information about the team is displayed
#define INFOBAR_HEIGHT 800
#define INFOBAR_WIDTH 320


// ===== Functions =====

// Function to display the full map
void display_field(SDL_Surface *screen, Square **map);

// display the red fog of war
void display_red(SDL_Surface *screen, Square **map);

// Display the blue team
void display_blue(SDL_Surface *screen, Square **map);

// Display all pawns of a team
void display_team(SDL_Surface *screen, Square **map, Player *players, int team_number);

// Display the field in function of the team
void display_teamVue(SDL_Surface *screen, Square **map, Player *players, int team_number);

// display the ennemie only when he is visible
void display_adv(SDL_Surface *screen, Square **map, SDL_Rect position, int team);

// Function to display the infobar according to the player's team
void display_infobar(SDL_Surface *screen, Player *players, int team_number);

// Display a curso to wich pawn is playing
void display_cursor(SDL_Surface *screen, Player player, int id);

// Display the menu
int main_menu(SDL_Surface *screen);

// Print the log on the screen and on a separated file
void print_log(SDL_Surface *screen, char *message);

void clear_log();


#endif //KAPTURE_2_DISPLAY_H
