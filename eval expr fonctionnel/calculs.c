/*
** EPITECH PROJECT, 2018
** CPool_evalexpr_bootstrap_2018
** File description:
** Does the calculs
*/

#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"
#include <unistd.h>

int operation_choser(char *str2, int a, int b, int i)
{
    int c = 0;

    switch (str2[i]) {
        case '+':
        c = addition(a, b);
        break;
        case '-':
        c = substraction(a, b);
        break;
        case '/':
        c = division(a, b);
        break;
        case '*':
        c = multiplication(a, b);
        break;
        case '%':
        c = modulo(a, b);
        break;
    }
    return (c);
}

int after_op(char *str2, int i)
{
    for (i = i + 2; str2[i - 1] != '\0'; i++) {
        if (str2[i] == '+' || str2[i] == '/' || str2[i] == '%' ||
        str2[i] == '*' || str2[i] == '-' || str2[i] == '\0') {
            return (i - 1);
        }
    }
}

int before_op(char *str2, int i)
{
    int a = i;

    for (a--; str2[a]; a--) {
        if (str2[a] == '+' || str2[a] == '/' || str2[a] == '%' ||
        str2[a] == '*' || (str2[a] == '-' &&
        (str2[a - 1] >= '0' && str2[a - 1] <= '9')))
            return (a + 1);
        if (a == 0)
            return (0);
    }
}

char *calculs_second(char *str2)
{
    int a = 0;
    int b = 0;
    int i = 1;
    int bef_int = 0;
    int aft_int = 0;
    char *small_str = NULL;

    for (i = 1; str2[i]; i++) {
        if (str2[i] == '-' || str2[i] == '+') {
            a = before_op(str2, i);
            b = after_op(str2, i);
            bef_int = before_op_str(str2, a, i);
            aft_int = after_op_str(str2, b, i);
            small_str = int_to_str(operation_choser(str2, bef_int, aft_int, i));
            str2 = combine_str(str2, small_str, a, b);
        }
    }
    return (still_op_tester(str2) ? calculs_second(str2) : str2);
}

char *calculs_first(char *str2)
{
    int a = 0;
    int b = 0;
    int i = 1;
    int bef_int = 0;
    int aft_int = 0;
    int result = 0;
    char *small_str = NULL;

    for (i; str2[i]; i++) {
        if (str2[i] == '*' || str2[i] == '/' || str2[i] == '%') {
            a = before_op(str2, i);
            b = after_op(str2, i);
            bef_int = before_op_str(str2, a, i);
            aft_int = after_op_str(str2, b, i);
            small_str = int_to_str(operation_choser(str2, bef_int, aft_int, i));
            str2 = combine_str(str2, small_str, a, b);
        }
    }
    if (still_op_prioritary(str2))
        str2 = calculs_second(str2);
    return (still_op_tester(str2) ? calculs_first(str2) : str2);
}
