/*
** bonus.h for bonus.h in /home/onehandedpenguin/CPool_bistro-matic/bonus/include/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Wed Nov  2 18:12:26 2016 Paul Laffitte
** Last update Sun Nov  6 18:12:52 2016 Thomas Arbona
*/

#ifndef BONUS_H_
# define BONUS_H_

# include "func/infin_pow.h"
# include "func/infin_sqrt.h"
# include "func/infin_fact.h"
# include "func/infin_opposite.h"
# include "func/infin_abs.h"
# include "func/transposition.h"
# include "func/answer.h"
# include "eval_func/eval_func.h"
# include "eval_vars/eval_vars.h"

# define OP_FUNC	7
# define OP_SEP		8
# define OP_VAR		9
# define OP_EGAL	10

# define UNDEFINED_FUNC	6

typedef struct	s_calc_func
{
  char		*name;
  int		nb_args;
  char		*(*func)(char **);
}		t_calc_func;

char		*handle_expr(char *expr);
int		check_func(char *str);
t_calc_func	*get_calc_func(char *name);
char		**split_root_sep(char *);
char		*add_par(char *expr);

extern t_calc_func g_calc_func[];

#endif /* !BONUS_H_ */
