##
## Makefile for libmy in /home/OneHandedPenguin/CPool_Day12
##
## Made by Paul Laffitte
## Login   <paul.laffitte@epitech.eu>
##
## Started on  Tue Oct 18 10:36:19 2016 Paul Laffitte
## Last update Sun May 21 18:32:48 2017 Arthur Chaloin
##

CC		=	gcc

SRCS		=	src/containers/creators.c	 	\
			src/containers/my_map.c		 	\
			src/containers/my_map2.c		\
			src/containers/my_map3.c		\
			src/containers/my_list.c		\
			src/containers/my_list2.c		\
			src/containers/my_list3.c		\
			src/containers/my_list4.c		\
			src/containers/my_list5.c		\
			src/containers/garbage.c		\
			src/utils/my_swap.c		 	\
			src/utils/my_malloc.c			\
			src/utils/my_hashs.c		 	\
			src/utils/my_parse_file.c		\
			src/utils/my_strcpy.c			\
			src/utils/my_err.c

OBJS		=	$(SRCS:.c=.o)

CPPFLAGS	=	-I./include/

CFLAGS		=	-W -Wall -Wextra

NAME		=	libpmy.a

RM		=	rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

debug:		CFLAGS += -g
debug:		CFLAGS += -Wno-error
debug:		re

check:		CC = clang
check:		fclean
		scan-build make all
		make fclean
