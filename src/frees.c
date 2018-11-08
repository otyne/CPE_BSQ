/*
** EPITECH PROJECT, 2018
** bsq
** File description:
** frees
*/

#include <stdlib.h>
#include "my.h"

void my_free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}

void my_free_int(int **tab, int max)
{
    for (int i = 0; i != max; i++)
        free(tab[i]);
    free(tab);
}