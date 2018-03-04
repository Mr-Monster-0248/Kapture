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
    int i, j, x;
    Square **map = (Square**) malloc(NBR_CASE_Y * sizeof(Square*));

    FILE* fichier = NULL;
    fichier = fopen(file_path,"r");

    if (fichier == NULL)
    {
        printf("il manque le fichier map.txt");
    }

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
        players[i] = (Player*) malloc((nbr_scout + nbr_infantryman + nbr_shock + 1) * sizeof(Player));
        for (j = 0; j < nbr_scout; j++)
        {
            players[i][j].id = j;
            players[i][j].type = SCOUT;
            players[i][j].flag = FALSE;
            players[i][j].actionPoint = PA_SCOUT;
        }
        for (j = j; j < (nbr_scout + nbr_infantryman); j++)
        {
            players[i][j].id = j;
            players[i][j].type = INFANTRYMAN;
            players[i][j].flag = FALSE;
            players[i][j].actionPoint = PA_INFANTRYMAN;
        }
        for (j = j; j < (nbr_scout + nbr_infantryman + nbr_shock); j++)
        {
            players[i][j].id = j;
            players[i][j].type = SHOCK_TROOPS;
            players[i][j].flag = FALSE;
            players[i][j].actionPoint = PA_SHOCK;
        }
        players[i][j].id = j;
        players[i][j].type = FLAG;
        players[i][j].flag = FALSE;
        players[i][j].actionPoint = 0;
    }

    return players;
}


void init_position(Square** map, Player** players, int number_team, int nbr_members)
{
    int i, flag_x, flag_y, x, y, team_number;

    for(team_number = 0; team_number < number_team; team_number ++)
    {
        flag_y = rand() % (NBR_CASE_Y - 6) + 3;
        if(team_number == 0)
            flag_x = 3;
        else
            flag_x = NBR_CASE_X - 4;
        map[flag_y][flag_x].pawn.type = FLAG;
        map[flag_y][flag_x].pawn.team = team_number + 1;
        players[team_number][nbr_members].position.x = flag_x;
        players[team_number][nbr_members].position.y = flag_y;

        for(i = 0; i < nbr_members; i++)
        {
            do
            {
                y = rand() % 4 + flag_y - 2;
                x = rand() % 4 + flag_x - 2;
            } while(map[y][x].pawn.type != EMPTY);

            map[y][x].pawn.type = players[team_number][i].type;
            map[y][x].pawn.team = team_number + 1;
            players[team_number][i].position.x = x;
            players[team_number][i].position.y = y;
        }
    }
}


void free_2D_array(void** array, int size_x)
{
    int i = 0;

    for (i = 0; i < size_x; i++)
        free(array[i]);

    free(array);
}
