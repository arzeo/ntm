/*
** EPITECH PROJECT, 2018
** CPool_evalexpr_bootstrap_2018
** File description:
** str_to_int
*/

#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"

int before_op_str(char *str2, int a, int i)
{
    int nbr = 0;
    int tmp_a = a;
    int neg = 1;

    if (str2[a] == '-') {
        tmp_a++;
        neg = neg * -1;
    }
    for (tmp_a; tmp_a < i; tmp_a++) {
        nbr = nbr + (str2[tmp_a] - 48);
        nbr = nbr * 10;
    }
    nbr = nbr / 10;
    if (neg == -1)
        nbr = nbr * -1;
    return (nbr);
}

int after_op_str(char *str2, int b, int i)
{
    int nbr = 0;
    int tmp_i = i + 1;
    int neg = 1;

    if (str2[tmp_i] == '-') {
        tmp_i++;
        neg = neg * -1;
    }
    for (tmp_i; tmp_i <= b; tmp_i++) {
        nbr = nbr + (str2[tmp_i] - 48);
        nbr = nbr * 10;
    }
    nbr = nbr / 10;
    if (neg == -1)
        nbr = nbr * -1;
    return (nbr);
}

char *combine_str(char *str2, char *small_str, int a, int b)
{
    int i = 0;
    char *combine_str = malloc(sizeof(char) * (my_strlen(str2) +
    (my_strlen(small_str) - ((a - b) + 1)) + 1));

    for (i; i < a; i++)
        combine_str[i] = str2[i];
    for (int c = 0; small_str[c] != '\0'; c++) {
        combine_str[i] = small_str[c];
        i++;
    }
    for (i; str2[b + 1] != '\0'; i++) {
        combine_str[i] = str2[b + 1];
        b++;
    }
    combine_str[i + 1] = '\0';
    free(str2);
    return (combine_str);
}
