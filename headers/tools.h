#ifndef TOOLS
    #define TOOLS

    #include "constant.h"

    // ======= Initialisatons =======

    // Initialisaton of the map with empty pawn and normal field
    Square** init_map();

    // ======= Other tools =======

    // Function to free a 2 dimentional array
    void free_2D_array(void** array, int size_x);

#endif
