/*
** EPITECH PROJECT, 2018
** CPool_evalexpr_2018
** File description:
** operators
*/

#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"

int addition(int a, int b)
{
    int total = a + b;
    return (total);
}

int substraction(int a, int b)
{
    int total = a - b;
    return (total);
}

int division(int a, int b)
{
    int total = a / b;
    return (total);
}

int multiplication(int a, int b)
{
    int total = a * b;
    return (total);
}

int modulo(int a, int b)
{
    int total = a % b;
    return (total);
}
