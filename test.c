#include "headers/constant.h"

//met la fenetre en pause
void pause();

int main(int argc, char *argv[])
{
    SDL_Surface *screen = NULL, *obj = NULL, *logscreen = NULL; //initialisation des variable de surface

    int continuer = 1;
    SDL_Event event;
    Uint32 colorkey;

    //initialisation des position
    SDL_Rect position;
    SDL_Rect p_log;

    position.x = 0;
    position.y = 0;

    p_log.x = 0;
    p_log.y = FIELD_HEIGHT;

    SDL_Init(SDL_INIT_VIDEO); //Demarage SDL en mode video
    SDL_WM_SetCaption("Kapture", NULL);// titre de la fenetre

    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE); //creation de la fenetre principal
    obj = SDL_CreateRGBSurface(SDL_HWSURFACE, CASE_WIDTH, CASE_HEIGHT, 32, 0, 0, 0, 0); //creation d'une surface
    logscreen = SDL_CreateRGBSurface(SDL_HWSURFACE, LOG_WIDTH, LOG_HEIGHT, 32, 0, 0, 0, 0);


    if (screen == NULL) // Si l'ouverture a échoué, on le note et on arrête
    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_FillRect(obj, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
    SDL_FillRect(logscreen, NULL, SDL_MapRGB(screen->format, 255, 255, 255)); //couleur pour surface obj
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 17, 206, 112)); //couleur pour surface screen

    SDL_BlitSurface(logscreen, NULL, screen, &p_log);
    SDL_BlitSurface(obj, NULL, screen, &position); //Blit de la surface obj sur screen
    SDL_Flip(screen); // Mise à jour de l'écran avec sa nouvelle couleur

    pause();

    // SDL_FreeSurface(img);
    SDL_FreeSurface(obj);
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
        }
    }
}
