#include "../headers/game.h"
#include "../headers/tools.h"

void game(SDL_Surface *screen, Square **map, Player **players)
{
    SDL_Surface *logscreen = NULL, *infobar = NULL;

    infobar = SDL_CreateRGBSurface(SDL_HWSURFACE, INFOBAR_WIDTH, INFOBAR_HEIGHT, 32, 0, 0, 0, 0); // Infobar init
    logscreen = SDL_CreateRGBSurface(SDL_HWSURFACE, LOG_WIDTH, LOG_HEIGHT, 32, 0, 0, 0, 0); // Log initialisation

    //initialisation des position
    SDL_Rect origine;
    SDL_Rect p_log, p_info;

    origine.x = 0;
    origine.y = 0;

    p_log.x = 0;
    p_log.y = FIELD_HEIGHT;

    p_info.x = FIELD_WIDHT;
    p_info.y = 0;

    SDL_FillRect(logscreen, NULL, SDL_MapRGB(screen->format, 255, 255, 255)); //couleur pour surface infobar

    init_position(map, players, NBR_OF_PLAYER, NBR_MEMBER);

    display_field(screen, map);

    SDL_BlitSurface(logscreen, NULL, screen, &p_log);
    SDL_BlitSurface(infobar, NULL, screen, &p_info);

    SDL_FreeSurface(logscreen);
    SDL_FreeSurface(infobar);
}
