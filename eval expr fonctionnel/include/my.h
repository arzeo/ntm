/*
** EPITECH PROJECT, 2018
** include
** File description:
** create an include
*/

#ifndef MY_H_
#define MY_H_

int after_op(char *str2, int i);
int operation_choser(char *str2, int a, int b, int i);
int before_op(char *str2, int i);
char *calculs_second(char *str2);
char *calculs_first(char *str2);
int iferror2(char *str);
int iferror(char *str);
int int_test(int nb);
char *my_revstr(char *str);
char *int_to_str(int nb);
char *my_strcpy(char const *src);
int my_strlen(char const *str);
int addition(int a, int b);
int substraction(int a, int b);
int division(int a, int b);
int multiplication(int a, int b);
int modulo(int a, int b);
int are_parenthesis_in(char *str);
char *parenthesis_remover(char *str, int a, int b, char *in_parenthesis);
char *parenthesis(char *str, int a, int b);
char *evalexpr(char const *av);
int main(int ac, char * const *av);
int before_op_str(char *str2, int a, int i);
int after_op_str(char *str2, int b, int i);
char *combine_str(char *str2, char *small_str, int a, int b);
int still_op_tester(char *str2);
int still_op_prioritary(char *str2);
#endif
