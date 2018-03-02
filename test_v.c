#include "constant.h"

Case** init_map();

int main(int argc, char *argv[])
{
    Case map[NBR_CASE_Y][NBR_CASE_X] = init_map();
    return 0;
}

Case** init_map()
{
    Case map[NBR_CASE_Y][NBR_CASE_X];
    int i, j;

    for (i = 0; i < NBR_CASE_Y; i++)
    {
        for (j = 0; j < NBR_CASE_X; j++)
        {
            map[i][j].field = NORMAL;
            map[i][j].pawn.team = 0;
            map[i][j].pawn.type = EMPTY;
            map[i][j].pawn.flag = FALSE;
            map[i][j].pawn.actionPoint = 0;
            map[i][j].visible_red = 0;
            map[i][j].visible_blue = 0;
        }
    }
    return map;
}
