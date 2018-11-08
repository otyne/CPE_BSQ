/*
** EPITECH PROJECT, 2018
** bsq
** File description:
** skeleton
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int *check_obs(int *save, int **uni, int i, int j)
{
    int rd = 0;
    int ru = 0;
    int ld = 0;
    int lu = 0;

    if (i <= save[3] - save[0] && j <= save[4] - save[0]) {
        rd = uni[i + save[0] - 1][j + save[0] - 1];
        if (i > 0 && j > 0)
            lu = uni[i - 1][j - 1];
        if (i > 0)
            ru = uni[i - 1][j + save[0] - 1];
        if (j > 0)
            ld = uni[i + save[0] - 1][j - 1];
        if (rd - ld - ru + lu == 0) {
            save[0] += 1;
            save[1] = i;
            save[2] = j;
            save = check_obs(save, uni, i, j);
        }
    }
    return (save);    
}

char **fill_new_map(char **map, int *save)
{
    int i = save[1];
    int j = save[2];

    for (int sl = 0; sl != save[0] - 1; sl++)
        for (int sc = 0; sc != save[0] - 1; sc++)
            map[i + sl][j + sc] = 'x';
    return (map);
}

char **algorithm_bsq(int **uni, char **map, int lines, int col)
{
    int i = 0;
    int j = 0;
    int *save = malloc(sizeof(int) * 5);

    save = fill_save(lines, col, save);
    for (i = 0; i != lines; i ++) {
        for (j = 0; j != col; j++) {
            save = check_obs(save, uni, i, j);
        }
    }
    map = fill_new_map(map, save);
    free(save);
    return (map);
}

void my_bsq(char *pre_map, int lines)
{
    char **map = malloc(sizeof(char *) * (lines + 1));
    int **uni = malloc(sizeof(int *) * lines);
    int col = get_col(pre_map);
    int k = 0;

    for (k = 0; k != lines; k++) {
        map[k] = malloc(col + 1);
        uni[k] = malloc(sizeof(int) * col);
        map[k] = my_strncpy(map[k], pre_map, col);
        uni[k] = my_intncpy(uni, k, pre_map, col);
        map[k][col] = '\0';
        pre_map += (col + 1);
    }
    map[k] = NULL;
    map = algorithm_bsq(uni, map, lines, col);
    draw_map(map);
    my_free_tab(map);
    my_free_int(uni, lines);
}

void init_start_bsq(char *pre_map, int lines)
{
    while (*pre_map != '\n' && *pre_map != '\0')
        pre_map += 1;
    my_bsq(pre_map + 1, lines);
}