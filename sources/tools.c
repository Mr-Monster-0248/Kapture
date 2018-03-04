#include "../headers/constant.h"

Square** init_map()
{
    int i, j;
    Square **map = (Square**) malloc(NBR_CASE_Y * sizeof(Square*));

    for (i = 0; i < NBR_CASE_Y; i++)
    {
        map[i] = (Square*) malloc(NBR_CASE_X * sizeof(Square));
        for (j = 0; j < NBR_CASE_X; j++)
        {
            map[i][j].field = NORMAL;
            map[i][j].pawn.team = 0;
            map[i][j].pawn.type = EMPTY;
            map[i][j].pawn.flag = FALSE;
            map[i][j].visible_red = 0;
            map[i][j].visible_blue = 0;
        }
    }

    return map;
}


Square** load_map(char *file_path)
{
    int i, j, k, x;
    Square **map = (Square**) malloc(NBR_CASE_Y * sizeof(Square*));

    FILE* fichier = NULL;
    fichier = fopen(file_path,"r");

    if (fichier == NULL)
    {
        printf("il manque le fichier map.txt");
    }


    k = 0;
    for (i = 0; i < NBR_CASE_Y; i++)
    {
        map[i] = (Square*) malloc(NBR_CASE_X * sizeof(Square));
        for (j = 0; j < NBR_CASE_X; j++)
        {
            x = fgetc(fichier);
            map[i][j].field = x-48;
            map[i][j].pawn.team = 0;
            map[i][j].pawn.type = EMPTY;
            map[i][j].pawn.flag = FALSE;
            map[i][j].visible_red = 0;
            map[i][j].visible_blue = 0;
            printf("%d",x-48);
        }
        fgetc(fichier);
    }
    fclose(fichier);
    return map;
}


Player** init_players(int number_team, int nbr_scout, int nbr_infantryman, int nbr_shock)
{
    int i, j;
    Player **players = (Player**) malloc(number_team * sizeof(Player*));

    for (i = 0; i < number_team; i++)
    {
        players[i] = (Player*) malloc((nbr_scout + nbr_infantryman + nbr_shock) * sizeof(Player));
        for (j = 0; j < nbr_scout; j++)
        {
            players[i][j].type = SCOUT;
            players[i][j].flag = FALSE;
            players[i][j].actionPoint = PA_SCOUT;
            players[i][j].x = 0;
            players[i][j].y = 0;
        }
        for (j; j < (nbr_scout + nbr_infantryman); j++)
        {
            players[i][j].type = INFANTRYMAN;
            players[i][j].flag = FALSE;
            players[i][j].actionPoint = PA_INFANTRYMAN;
            players[i][j].x = 0;
            players[i][j].y = 0;
        }
        for (j; j < (nbr_scout + nbr_infantryman + nbr_shock); j++)
        {
            players[i][j].type = SHOCK_TROOPS;
            players[i][j].flag = FALSE;
            players[i][j].actionPoint = PA_SHOCK;
            players[i][j].x = 0;
            players[i][j].y = 0;
        }
    }

    return players;
}


void free_2D_array(void** array, int size_x)
{
    int i = 0;

    for (i = 0; i < size_x; i++)
        free(array[i]);

    free(array);
}
