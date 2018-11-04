/*
** EPITECH PROJECT, 2018
** CPool_evalexpr_bootstrap_2018
** File description:
** int to str
*/

#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"

int int_test(int nb)
{
    int a = 0;
    int ret = 0;
    int i = 0;

    if (nb < 0) {
        ret = 1;
        nb = nb * -1;
    }
    for (i; nb != 0; i++)
        nb = nb / 10;
    ret == 1 ? i = i + 1 : 0;
    return (i);
}

char *my_revstr(char *str)
{
    int a = 0;
    int tmp;
    int b = 0;
    char letter;

    while (str[a] != '\0') {
        a++;
    }
    tmp = a - 1;

    while (tmp >= b) {
        letter = str[tmp];
        str[tmp] = str[b];
        str[b] = letter;
        b++;
        tmp--;
    }
    return (str);
}

char *int_to_str(int nb)
{
    char *str = malloc(sizeof(char) * (int_test(nb) + 1));
    int a = 0;
    int b = 0;
    int ret = 0;
    int i = 0;

    if (nb == 0)
        return (str = "0\0");
    if (nb < 0) {
        ret = 1;
        nb = nb * -1;
    }
    for (i; nb != 0; i++) {
        str[i] = nb % 10;
        str[i] = str[i] + '0';
        nb = nb / 10;
    }
    ret == 1 ? str[i] = '-' : 0;
    str[i + 1] = '\0';
    return (my_revstr(str));
}
