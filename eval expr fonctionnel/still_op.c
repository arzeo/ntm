/*
** EPITECH PROJECT, 2018
** CPool_evalexpr_2018
** File description:
** if there's still operations
*/

#include "include/my.h"

int still_op_tester(char *str2)
{
    for (int i = 0; str2[i] != '\0'; i++)
        if (str2[i] == '/' || str2[i] == '*' || str2[i] == '+' || str2[i] == '%'
        || (str2[i] == '-' && (str2[i - 1] >= '0' && str2[i - 1] <= '9')))
            return (1);
        return (0);
}

int still_op_prioritary(char *str2)
{
    for (int i = 0; str2[i] != '\0'; i++)
        if (str2[i] == '/' || str2[i] == '*' || str2[i] == '%')
            return (0);
        return (1);
}
