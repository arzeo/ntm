##
## EPITECH PROJECT, 2018
## CPool_Day10_2018
## File description:
## makefile
##

SRC		=	my_strlen.c			\
			my_strcpy.c			\
			iferror.c			\
			calculs.c			\
			parenthesis.c		\
			str_to_int.c		\
			operators.c			\
			int_to_str.c		\
			still_op.c

OBJ		=	$(SRC:.c=.o)

NAME	=	evalexpr

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -g

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
