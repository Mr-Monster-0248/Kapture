#include "../headers/constant.h"
#include "../headers/display.h"
#include "../headers/tools.h"

void pause();

int main(int argc, char *argv[])
{
    srand(time(NULL));

    // Initialisation of surface variables
    SDL_Surface *screen = NULL; // principal screen
    SDL_Surface *infobar = NULL, *logscreen = NULL;
    SDL_Surface *normal = NULL; // *forest = NULL, *river = NULL; // Field sprites

    int continuer = 1;
    Square **map = load_map("map.txt");
    Player **players = init_players(2, 4, 2, 1);

    SDL_Event event;
    Uint32 colorkey;

    //initialisation des position
    SDL_Rect origine;
    SDL_Rect p_log, p_info;

    origine.x = 0;
    origine.y = 0;

    p_log.x = 0;
    p_log.y = FIELD_HEIGHT;

    p_info.x = FIELD_WIDHT;
    p_info.y = 0;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetCaption("Kapture", NULL);

    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF); // main window init
    infobar = SDL_CreateRGBSurface(SDL_HWSURFACE, INFOBAR_WIDTH, INFOBAR_HEIGHT, 32, 0, 0, 0, 0); // Infobar init
    logscreen = SDL_CreateRGBSurface(SDL_HWSURFACE, LOG_WIDTH, LOG_HEIGHT, 32, 0, 0, 0, 0); // Log initialisation

    if (screen == NULL) // Si l'ouverture a échoué, on le note et on arrête
    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_FillRect(infobar, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
    SDL_FillRect(logscreen, NULL, SDL_MapRGB(screen->format, 255, 255, 255)); //couleur pour surface infobar
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 17, 206, 112)); //couleur pour surface screen

    init_position(map, players, 2, 7);

    display_field(screen, map);

    SDL_BlitSurface(logscreen, NULL, screen, &p_log);
    SDL_BlitSurface(infobar, NULL, screen, &p_info); //Blit de la surface infobar sur screen
    SDL_BlitSurface(normal, NULL, screen, &origine);
    SDL_Flip(screen); // Mise à jour de l'écran avec sa nouvelle couleur

    pause();

    SDL_FreeSurface(normal);
    // SDL_FreeSurface(river);
    // SDL_FreeSurface(forest);
    SDL_FreeSurface(logscreen);
    SDL_FreeSurface(infobar);
    SDL_Quit();
    return 0;
}

void pause()
{
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_ESCAPE)
                    continuer = 0;
                break;
        }
    }
}
