#ifndef TOOLS
    #define TOOLS

    #include "constant.h"

    // ======= Initialisatons =======

    // Initialisaton of the map with empty pawn and normal field
    Square** init_map();

    // Initialize a map from a file
    Square** load_map(char *file_path);

    // Initialisaton of the teams
    Player** init_players(int number_team, int nbr_scout, int nbr_infantryman, int nbr_shock);

    // ======= Other tools =======

    // Function to free a 2 dimentional array
    void free_2D_array(void** array, int size_x);

#endif
