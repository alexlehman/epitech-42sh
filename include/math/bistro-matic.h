/*
** bistro-matic.h for bistro-matic in /home/arthur/Documents/Piscine/Projets/CPool_bistro-matic/include/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Thu Oct 27 15:44:38 2016 Arthur Chaloin
** Last update Sun Nov  6 20:28:48 2016 Arthur Chaloin
*/

#ifndef BISTRO_MATIC_H_
# define BISTRO_MATIC_H_

# include <unistd.h>
# include <stdlib.h>

# include "error.h"
# include "ressources.h"
# include "eval_expr/eval_expr.h"
# include "infin_add/infin_add.h"
# include "karatsuba/karatsuba.h"
# include "infin_div/infin_div.h"

# define SYNTAX_ERROR_MSG	"syntax error"
# define ERROR_MSG		"Error"
# define MALLOC_FAILED		12
# define DIV_BY_ZERO		21
# define SYNTAX_ERR		42
# define EXIT_ERROR		84
# define SQRT_NEG		168
# define FACT_NEG		336

# define OP_PAR_O	0
# define OP_PAR_C	1
# define OP_ADD		2
# define OP_SUB		3
# define OP_MUL		4
# define OP_DIV		5
# define OP_MOD		6

# define MAX(x, y)	((x > y) ? x : y)
# define MIN(x, y)	((x < y) ? x : y)

typedef struct	s_arithmetic
{
  char		*base;
  char		*ops;
  int		len_base;
  char		ope_low[3];
  char		ope_high[4];
}		t_arithmetic;

extern t_arithmetic g_arithmetic;

#endif /* !BISTRO-MATIC_H_ */
