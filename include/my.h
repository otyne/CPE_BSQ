/*
** EPITECH PROJECT, 2018
** lib.h
** File description:
** lib.h
*/

#ifndef MY_H_
#define MY_H_

/* STRUCTS */


/* PROG FUNCS */

void init_start_bsq(char *, int);
int get_col(char *);
void draw_map(char **);
void draw_int(int **, int, int);
void my_free_tab(char **);
void my_free_int(int **, int);
int *my_intncpy(int **, int, char *, int);
int *fill_save(int, int, int *);

/* LIB FUNCS */

char **my_str_to_word_array_sep(char *, char);
int my_getnbr(char *);
void my_putchar(char);
char *read_file(char *);
int my_putstr(char *);
int my_put_nbr(int);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_revstr(char *);
char *my_strstr(char *, char *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);
char *my_strupcase(char *);
char *my_strlowcase(char *);
char *my_strcapitalize(char *);
int my_str_isalpha(char *);
int my_str_isnum(char *);
int my_str_islower(char *);
int my_str_isupper(char *);
int my_str_isprintable(char *);
int my_putnbr_base(int, char const *);
int my_getnbr_base(char const *, char const *);
int my_showstr(char const *);
int my_showmem(char const *, int);
void my_print_params(int, char **);
void my_rev_params(int, char **);
void my_sort_params(int, char **);
int my_strlen(char *);

#endif
