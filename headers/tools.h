//
// Created by Thibault Lepez on 06/01/2023.
//

#ifndef KAPTURE_2_TOOLS_H
#define KAPTURE_2_TOOLS_H

#include "constant.h"

// ======= Initialisatons =======

// Initialisaton of the map with empty pawn and normal field
Square **init_map();

// Initialize a map from a file
Square **load_map(char *file_path);

// Initialisaton of the teams
Player **init_players(int number_team, int nbr_scout, int nbr_infantryman, int nbr_shock);

// Place pawns for the first time
void init_position(Square **map, Player **players, int number_team, int nbr_members);


// ======= Map discovery ========

// Unlock map for teams
void discover_map(Square **map, SDL_Rect position, int team);


// ======= Other tools =======

// Function to free a 2 dimentional array
void free_2D_array(void **array, int size_x);

void check_alloc(void *p);

#endif //KAPTURE_2_TOOLS_H
