/*
** EPITECH PROJECT, 2018
** my
** File description:
** my_strlen
*/

#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"

int my_strlen(char const *str)
{
    int a = 0;

    while (str[a] != '\0') {
        a++;
    }
    return (a);
}
