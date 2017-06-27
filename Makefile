##
## Makefile for 42sh in /Users/arthur/Dev/B2/PSU/PSU_2016_42sh/
##
## Made by Arthur Chaloin
## Login   <arthur.chaloin@epitech.eu>
##
## Started on  Sat Apr 22 22:02:42 2017 Arthur Chaloin
## Last update Tue May 30 14:05:08 2017 Thomas ARBONA
##

NAME	=	42sh

CC	=	gcc

RM	=	rm -f

CFLAGS	=	-W -Wall -Wextra -g
CFLAGS	+=	-I./include/
CFLAGS	+=	-I./include/math/

LDFLAGS	=	-L./lib/pmy -lpmy -L./lib/tmy -ltmy

SRC	=	src/main.c					\
		src/core/core.c					\
		src/core/exec/exec.c				\
		src/core/exec/launch.c				\
		src/core/exec/op_in.c				\
		src/core/exec/op_out.c				\
		src/core/exec/op_logic.c			\
		src/core/error.c				\
		src/core/complete/complete.c			\
		src/core/complete/select.c			\
		src/core/complete/dir.c				\
		src/core/input/input.c				\
		src/core/input/handling.c			\
		src/core/history/history.c			\
		src/core/globing/globing.c			\
		src/core/scripting.c				\
		src/core/eval.c					\
		src/parser/parser.c				\
		src/parser/parser_error.c			\
		src/parser/parser_pipe.c			\
		src/parser/parser_logic.c			\
		src/parser/parser_redir.c			\
		src/parser/parser_sep.c				\
		src/parser/parser_syntax.c			\
		src/parser/node.c				\
		src/builtins/cd.c				\
		src/builtins/echo.c				\
		src/builtins/alias.c				\
		src/builtins/source.c				\
		src/builtins/env.c				\
		src/builtins/setenv.c				\
		src/builtins/unsetenv.c				\
		src/builtins/where.c				\
		src/builtins/which.c				\
		src/builtins/exit.c				\
		src/builtins/if.c				\
		src/builtins/if2.c				\
		src/builtins/if3.c				\
		src/builtins/while.c				\
		src/builtins/set.c				\
		src/builtins/unset.c				\
		src/builtins/repeat.c				\
		src/builtins/foreach.c				\
		src/builtins/read.c				\
		src/init/init.c					\
		src/init/signal.c				\
		src/utils/strsplit.c				\
		src/utils/read.c				\
		src/utils/lexer.c				\
		src/utils/inhibitors.c				\
		src/utils/iterator.c				\
		src/utils/separators.c				\
		src/math/math.c					\
		src/math/error.c				\
		src/math/syntax.c				\
		src/math/ressources/number.c			\
		src/math/eval_expr/eval_expr.c			\
		src/math/eval_expr/gentree.c			\
		src/math/eval_expr/handle_tree.c		\
		src/math/eval_expr/calculate_tree.c		\
		src/math/eval_expr/operations.c			\
		src/math/eval_expr/lexer/lexer.c		\
		src/math/eval_expr/lexer/lexer_util.c		\
		src/math/eval_expr/lexer/normalize_sign.c	\
		src/math/infin_add/infin_add.c			\
		src/math/infin_add/infin_add_util.c		\
		src/math/karatsuba/karatsuba.c			\
		src/math/karatsuba/karatsuba_util.c		\
		src/math/infin_div/infin_div.c			\
		src/math/func_error.c				\
		src/math/func/infin_pow.c			\
		src/math/func/infin_sqrt.c			\
		src/math/func/infin_fact.c			\
		src/math/func/infin_opposite.c			\
		src/math/func/infin_abs.c			\
		src/math/func/transposition.c			\
		src/math/func/answer.c				\
		src/math/eval_vars/eval_vars.c			\
		src/math/eval_vars/eval_vars_util.c		\
		src/math/eval_func/eval_func.c			\
		src/math/eval_func/exec_func.c			\
		src/math/split_root_sep.c			\
		src/math/add_par.c

OBJ	=	$(SRC:.c=.o)

all:
	make -C lib/pmy/
	make -C lib/tmy/
	make $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(LDFLAGS) -o $(NAME)

clean:
	make clean -C lib/pmy/
	make clean -C lib/tmy/
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)
	$(RM) lib/pmy/libpmy.a
	$(RM) lib/tmy/libtmy.a

re:	fclean all

debug:	CFLAGS += -g
debug:	re

fast:	CFLAGS += -O3 -Ofast -Wno-maybe-uninitialized -Wno-unused-result
fast:	re

coffee:
	@echo "    (  )   (   )  )\n     ) (   )  (  (\n     ( )  (    ) )\n     _____________\n    <_____________> ___\n    |             |/ _ \\ \n    |               | | |\n    |               |_| |\n ___|             |\___/\n/    \___________/    \\ \n\_____________________/"

.PHONY:	all clean fclean re debug fast coffee
