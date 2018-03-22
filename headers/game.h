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

    // ===== GAME MODE =====
    #define MOVE 1
    #define FIGHT 2
    #define TAKE_FLAG 3
    #define GIVE_FLAG 4

    // Main game fonction
    void game(SDL_Surface *screen, Square **map, Player **players);

    // Function that execut a game turn
    int game_turn(SDL_Surface *screen, Square **map, Player **players, int team_number);

    // Move a pawn to an other position
    void move_pawn(int id, Player** players, Square** map, SDL_Rect prev_loc, SDL_Rect new_loc);

    // give the winner of a fight according to the type of pawn
    int fight(int player1, int player2);

    // Function to handle battle
    void start_fight(Square **map, Player **players, SDL_Rect pos_atk, SDL_Rect pos_def);

    // Check if a move is possible
    int check_move(Square **map, SDL_Rect position, int team);

    // Function to try to win the game
    int give_flag(Square **map, Player players, SDL_Rect pos_f);

    // Function to take the flag
    void take_flag(Square **map, Player **players, int id, int team, SDL_Rect pos_p, SDL_Rect pos_f);

    // remove the right number of PA in funtion on the fild the pawn is leaving
    int remove_pa(Square **map, Player player);

    // Give back pa to players
    void give_pa(Player **players);


#endif
