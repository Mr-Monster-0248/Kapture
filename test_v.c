#include "headers/constant.h"

Square** init_map();

int main(int argc, char *argv[])
{
    Square **map = init_map();

    return 0;
}

Square** init_map()
{
    int i, j, k, x;
    Square **map = (Square**) malloc(NBR_CASE_Y * sizeof(Square*));

    FILE* fichier = NULL;
    fichier = fopen("map.txt","r");

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
            map[i][j].pawn.actionPoint = 0;
            map[i][j].visible_red = 0;
            map[i][j].visible_blue = 0;
            printf("%d",x-48);
        }
        fgetc(fichier);
    }
    fclose(fichier);
    return map;
}
