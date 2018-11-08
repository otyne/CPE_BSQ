/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

static int usage(int a)
{
    if (a == 0) {
        write(2, "USAGE :\n./bsq\t[filepath]\nfilepath ", 34);
        write(2, ": path of the file containing the map.\n", 39);
    }
    if (a == 1)
        write(2, "Error from file.\n", 17);
    return (84);
}

int main(int ac, char **av)
{
    char *pre_map = NULL;
    int line = 0;

    if (ac != 2)
        return (usage(0));
    pre_map = read_file(av[1]);
    line = my_getnbr(pre_map);
    if (pre_map == NULL || line == 0)
        return (usage(1));
    init_start_bsq(pre_map, line);
    free(pre_map);
    return (0);
}
