#include "../headers/game.h"
#include "../headers/tools.h"


void pause();

int main(int argc, char *argv[])
{
    srand(time(NULL));

    SDL_Surface *screen = NULL; // principal screen

    Square **map = load_map("map.txt");
    Player **players = init_players(NBR_OF_PLAYER, NBR_SCOUT, NBR_INFANTRYMAN, NBR_SHOCK);

    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetCaption("Kapture", NULL);

    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF); // main window init

    if (screen == NULL) // Si l'ouverture a échoué, on le note et on arrête
    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    clear_log();

    print_log(screen, "Map loaded");
    print_log(screen, "Teams initialized");

    game(screen, map, players);

    SDL_Flip(screen); // Mise à jour de l'écran avec sa nouvelle couleur

    pause();

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
