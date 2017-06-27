##
## Makefile for D10 in /home/arbona/CPool/CPool_Day10
##
## Made by Thomas Arbona
## Login   <arbona@epitech.net>
##
## Started on  Fri Oct 14 08:34:01 2016 Thomas Arbona
## Last update Sun May 21 18:32:29 2017 Arthur Chaloin
##

CC	=	gcc

SRC	=	convert_base.c		\
		my_find_prime_sup.c	\
		my_getnbr_base.c	\
		my_getnbr.c		\
		my_isneg.c		\
		my_is_prime.c		\
		my_power_rec.c		\
		my_putchar.c		\
		my_putnbr_base.c	\
		my_put_nbr.c		\
		my_putstr.c		\
		my_revstr.c		\
		my_showmem.c		\
		my_showstr.c		\
		my_show_wordtab.c	\
		my_sort_int_tab.c	\
		my_square_root.c	\
		my_strcapitalize.c	\
		my_strcat.c		\
		my_strcmp.c		\
		my_strcpy.c		\
		my_strdup.c		\
		my_strndup.c		\
		my_str_isalpha.c	\
		my_str_islower.c	\
		my_str_isnum.c		\
		my_str_isprintable.c	\
		my_str_isupper.c	\
		my_strlen.c		\
		my_strlowcase.c		\
		my_strncat.c		\
		my_strncmp.c		\
		my_strncpy.c		\
		my_strstr.c		\
		my_str_to_wordtab.c	\
		my_strupcase.c		\
		my_swap.c		\
		my_swapchar.c		\
		my_swapstr.c		\
		my_find_in_wordtab.c	\
		my_memset.c		\
		my_str_contain.c	\
		my_tablen.c		\
		my_replace_char.c	\
		my_str_replace.c	\
		my_int_to_base.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -I./include/

NAME	=	libtmy.a

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc libtmy.a $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
