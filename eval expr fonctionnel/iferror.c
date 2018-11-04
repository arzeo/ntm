/*
** EPITECH PROJECT, 2018
** CPool_evalexpr_bootstrap_2018
** File description:
** this function is useful in case of an error
*/

#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"

int iferror2(char *str)
{
    int a = 0;
    int b = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(')
            a++;
        if (str[i] == ')')
            b++;
    }
    if (b != a)
        return (1);
    return (0);
}

int iferror(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str[i] == '-' || str[i] == '+' || str[i] == '*' || str[i] == '%'
        || str[i] == '/' || (str[i] <= '9' && str[i] >= '0') || str[i] == '(' ||
        str[i] == ')'))
            return (1);
        if ((str[i] == '-' || str[i] == '+' || str[i] == '*' || str[i] == '%'
        || str[i] == '/') && (str[i + 1] == '*' || str[i + 1] == '%'
        || str[i + 1] == '/'))
            return (1);
        if ((str[i] == '*' || str[i] == '%' || str[i] == '/') &&
        (!((str[i + 1] <= '9' && str[i + 1] >= '0') || str[i + 1] == '(')
        || !((str[i - 1] <= '9' && str[i - 1] >= '0') || str[i - 1] == ')')))
            return (0);
    }
    if (iferror2(str))
        return (1);
    return (0);
}
