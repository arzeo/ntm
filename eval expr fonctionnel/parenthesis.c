/*
** EPITECH PROJECT, 2018
** CPool_evalexpr_bootstrap_2018
** File description:
** parsing
*/

#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"
#include <unistd.h>

int are_parenthesis_in(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == '(' || str[i] == ')')
            return (0);
    }
    return (1);
}

char *parenthesis_remover(char *str, int a, int b, char *in_parenthesis)
{
    char *str_par_off = NULL;
    int i = 0;
    int start = 0;

    if (a == 0)
        return(in_parenthesis);
    str_par_off = malloc(sizeof(char) * (my_strlen(str) + 10));
    for (i; i != a; i++)
        str_par_off[i] = str[i];
    for (i; in_parenthesis[start] != '\0'; i++) {
        str_par_off[i] = in_parenthesis[start];
        start++;
    }
    start = b;
    for (i;str[b + 1] != '\0'; i++) {
        str_par_off[i] = str[b + 1];
        b++;
    }
    str_par_off[i] = '\0';
    return (str_par_off);
}

char *parenthesis(char *str, int a, int b)
{
    int tmp_a = 0;
    char *str_parenthesis;

    str_parenthesis = malloc(sizeof(char) * (b - a + 2));
    str_parenthesis[b - a] = '\0';
    for (int i = 0; a + i + 1 < b; i++)
        str_parenthesis[i] = str[a + i + 1];
    return (a > 0 ? calculs_first(str_parenthesis) : calculs_first(str));
}

char *evalexpr(char const *av)
{
    char *str = NULL;
    char *in_parenthesis = NULL;
    int a = 0;
    int b = 0;

    str = my_strcpy(av);
    if (iferror(str))
        return (str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(')
            a = i;
        if (str[i] == ')') {
            b = i;
            break;
        }
    }
    in_parenthesis = parenthesis(str, a, b);
    str = parenthesis_remover(str, a, b, in_parenthesis);
    return (are_parenthesis_in(str) ? calculs_first(str) : evalexpr(str));
}

int main(int ac, char * const *av)
{
    char *str_end = NULL;

    str_end = evalexpr(av[1]);
    write(1, str_end, my_strlen(str_end));
    return (0);
}
