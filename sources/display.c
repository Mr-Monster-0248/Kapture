#include "../headers/display.h"
#include "../headers/game.h"

void display_field(SDL_Surface *screen, Square **map)
{
    int i, j;
    SDL_Rect position;
    SDL_Surface *normal = NULL, *forest = NULL, *river = NULL; // Field sprites
    SDL_Surface *flag1 = NULL, *scout1 = NULL, *infantryman1 = NULL, *shock1 = NULL;
    SDL_Surface *flag2 = NULL, *scout2 = NULL, *infantryman2 = NULL, *shock2 = NULL;

    Uint32 colorkey = SDL_MapRGB(screen->format, 0, 0, 255);

    normal = SDL_LoadBMP("image/NORMAL.bmp");
    forest = SDL_LoadBMP("image/FOREST.bmp");
    river = SDL_LoadBMP("image/RIVER.bmp");

    flag1 = SDL_LoadBMP("image/FLAG_1.bmp");
    scout1 = SDL_LoadBMP("image/SCOUT_1.bmp");
    infantryman1 = SDL_LoadBMP("image/INFANTRYMAN_1.bmp");
    shock1 = SDL_LoadBMP("image/SHOCK_1.bmp");

    flag2 = SDL_LoadBMP("image/FLAG_2.bmp");
    scout2 = SDL_LoadBMP("image/SCOUT_2.bmp");
    infantryman2 = SDL_LoadBMP("image/INFANTRYMAN_2.bmp");
    shock2 = SDL_LoadBMP("image/SHOCK_2.bmp");

    SDL_SetColorKey(flag1, SDL_SRCCOLORKEY, colorkey);
    SDL_SetColorKey(scout1, SDL_SRCCOLORKEY, colorkey);
    SDL_SetColorKey(infantryman1, SDL_SRCCOLORKEY, colorkey);
    SDL_SetColorKey(shock1, SDL_SRCCOLORKEY, colorkey);

    SDL_SetColorKey(flag2, SDL_SRCCOLORKEY, colorkey);
    SDL_SetColorKey(scout2, SDL_SRCCOLORKEY, colorkey);
    SDL_SetColorKey(infantryman2, SDL_SRCCOLORKEY, colorkey);
    SDL_SetColorKey(shock2, SDL_SRCCOLORKEY, colorkey);

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

            if(map[i][j].pawn.team == 1)
            {
                switch (map[i][j].pawn.type)
                {
                    case SCOUT:
                        SDL_BlitSurface(scout1, NULL, screen, &position);
                        break;
                    case INFANTRYMAN:
                        SDL_BlitSurface(infantryman1, NULL, screen, &position);
                        break;
                    case SHOCK_TROOPS:
                        SDL_BlitSurface(shock1, NULL, screen, &position);
                        break;
                    case FLAG:
                        SDL_BlitSurface(flag1, NULL, screen, &position);
                        break;
                }
            }
            else
            {
                switch (map[i][j].pawn.type)
                {
                    case SCOUT:
                        SDL_BlitSurface(scout2, NULL, screen, &position);
                        break;
                    case INFANTRYMAN:
                        SDL_BlitSurface(infantryman2, NULL, screen, &position);
                        break;
                    case SHOCK_TROOPS:
                        SDL_BlitSurface(shock2, NULL, screen, &position);
                        break;
                    case FLAG:
                        SDL_BlitSurface(flag2, NULL, screen, &position);
                        break;
                }
            }
        }
    }

    SDL_FreeSurface(normal);
    SDL_FreeSurface(river);
    SDL_FreeSurface(forest);
}


void display_infobar(SDL_Surface *screen, Player *players, int team_number)
{
    int i;
    SDL_Surface *infobar = NULL;
    SDL_Surface *pawns_info[NBR_MEMBER] = {NULL};

    Uint32 colorkey = SDL_MapRGB(screen->format, 0, 0, 255);


    SDL_Rect position;

    position.x = FIELD_WIDHT;
    position.y = 0;

    if(team_number == 1)
    {
        infobar = SDL_LoadBMP("image/INFOBAR_1.bmp");
        check_alloc(infobar);
        for(i = 0; i < NBR_MEMBER; i++)
        {
            if(i < NBR_SCOUT)
                pawns_info[i] = SDL_LoadBMP("image/SCOUT_INFO_1.bmp");
            else if(i < NBR_SCOUT + NBR_INFANTRYMAN)
                pawns_info[i] = SDL_LoadBMP("image/INFANTRYMAN_INFO_1.bmp");
            else
                pawns_info[i] = SDL_LoadBMP("image/SHOCK_INFO_1.bmp");

            SDL_SetColorKey(pawns_info[i], SDL_SRCCOLORKEY, colorkey);
        }
    }
    else
    {
        infobar = SDL_LoadBMP("image/INFOBAR_2.bmp");
        check_alloc(infobar);
        for(i = 0; i < NBR_MEMBER; i++)
        {
            if(i < NBR_SCOUT)
                pawns_info[i] = SDL_LoadBMP("image/SCOUT_INFO_2.bmp");
            else if(i < NBR_SCOUT + NBR_INFANTRYMAN)
                pawns_info[i] = SDL_LoadBMP("image/INFANTRYMAN_INFO_2.bmp");
            else
                pawns_info[i] = SDL_LoadBMP("image/SHOCK_INFO_2.bmp");

            SDL_SetColorKey(pawns_info[i], SDL_SRCCOLORKEY, colorkey);
        }
    }

    SDL_BlitSurface(infobar, NULL, screen, &position);

    position.y = position.y + 150;
    for(i = 0; i < NBR_MEMBER; i++)
    {
        SDL_BlitSurface(pawns_info[i], NULL, screen, &position);
        position.y = position.y + 40;
    }

    SDL_Flip(screen);

    SDL_FreeSurface(infobar);
    for(i = 0; i < NBR_MEMBER; i++)
        SDL_FreeSurface(pawns_info[i]);
}


void print_log(SDL_Surface *screen, char *message)
{
    FILE* logfile = NULL;
    logfile = fopen("game.log","a");
    fprintf(logfile, "%s\n", message);
    fclose(logfile);
}

void clear_log()
{
    FILE* logfile = NULL;
    logfile = fopen("game.log","w+");
    fprintf(logfile, "");
    fclose(logfile);
}
