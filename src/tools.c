/*
** EPITECH PROJECT, 2018
** bsq
** File description:
** tools
*/

#include <unistd.h>
#include "my.h"

int *fill_save(int lines, int col, int *save)
{
    save[0] = 1;
    save[1] = 0;
    save[2] = 0;
    save[3] = lines;
    save[4] = col;
    return (save);
}

int *my_intncpy(int **uni, int k, char *pre_map, int col)
{
    int i = 0;
    int val = 0;

    while (pre_map[i] != '\0' && i != col) {
        val += (pre_map[i] == 'o') ? 1 : 0;
        val -= (i != 0 && k != 0) ? uni[k - 1][i - 1] : 0;
        val += (k != 0) ? uni[k - 1][i] : 0;
        val += (i != 0) ? uni[k][i - 1] : 0;
        uni[k][i] = val;
        val = 0;
        i += 1;
    }
    return (uni[k]);
}

void draw_int(int **map, int max_li, int max_co)
{
    for (int i = 0; i != max_li; i++) {
        for (int j = 0; j != max_co; j++) {
            my_put_nbr(map[i][j]);
            my_putchar(' ');
        }
        my_putchar('\n');
    }
}

void draw_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        my_putstr(map[i]);
        my_putchar('\n');
    }
}

int get_col(char *pre_map)
{
    int len = 0;

    while (pre_map[len] != '\n')
        len += 1;
    return (len);
}