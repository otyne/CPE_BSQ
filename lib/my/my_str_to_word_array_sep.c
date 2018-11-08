/*
** EPITECH PROJECT, 2018
** my str to word array
** File description:
** str to word ta
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>

static int nb_words_sep(char const *str, char sep)
{
    int i = 0;
    int words = 0;

    while (str[i] != '\0') {
        if (str[i] == sep) {
            words += 1;
        }
        while (str[i] != sep && str[i] != '\0')
            i += 1;
        if (str[i] != '\0')
            i += 1;
    }
    return (words);
}

static int word_len_sep(char const *str, int k, char sep)
{
    int len = 0;

    while (str[k] != sep) {
        k += 1;
        len += 1;
    }
    return (len);
}

char **my_str_to_word_array_sep(char const *str, char sep)
{
    char **array = malloc(sizeof(char *) * (nb_words_sep(str, sep) + 1));
    int i = 0;
    int k = 0;
    int a = 0;

    while (i != nb_words_sep(str, sep)) {
        a = 0;
        while (str[k] == sep)
            k += 1;
        array[i] = malloc(sizeof(char) * (word_len_sep(str, k, sep) + 1));
        while (str[k] != sep) {
            array[i][a] = str[k];
            a += 1;
            k += 1;
        }
        array[i][a] = '\0';
        i += 1;
    }
    array[i] = NULL;
    return (array);
}
