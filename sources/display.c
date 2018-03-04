#include "../headers/display.h"

void display_field(SDL_Surface *screen, Square **map)
{
    int i, j;
    SDL_Rect position;
    SDL_Surface *normal = NULL, *forest = NULL, *river = NULL; // Field sprites


    normal = SDL_LoadBMP("image/NORMAL.bmp");
    forest = SDL_LoadBMP("image/FOREST.bmp");
    river = SDL_LoadBMP("image/RIVER.bmp");

    for(i = 0; i < NBR_CASE_Y; i++)
    {
        for(j = 0; j < NBR_CASE_X; j++)
        {
            position.x = j * SQUARE_WIDTH;
            position.y = i * SQUARE_WIDTH;

            switch(map[i][j].field)
            {
                case NORMAL:
                    SDL_BlitSurface(normal, NULL, screen, &position);
                    break;
                case FOREST:
                    SDL_BlitSurface(forest, NULL, screen, &position);
                    break;
                case RIVER:
                    SDL_BlitSurface(river, NULL, screen, &position);
                    break;
            }
        }
    }

    SDL_FreeSurface(normal);
    SDL_FreeSurface(river);
    SDL_FreeSurface(forest);
}
