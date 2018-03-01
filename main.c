#include "constant.h"

int main(int argc, char *argv[])
{
    Case map;

    map.field = FOREST;
    map.pawn.team = 1;
    map.pawn.type = SCOUT;
    map.pawn.actionPoint = 5;
    map.visible_red = TRUE;

    printf("field = %d\nteam = %d\ntype = %d\n", map.field, map.pawn.team, map.pawn.type);

    return 0;
}
