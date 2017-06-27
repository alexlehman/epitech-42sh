/*
** syntax.c for bistro-matic in /home/arthur/Documents/Piscine/Projects/CPool_bistro-matic/src/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Fri Nov  4 11:51:48 2016 Arthur Chaloin
** Last update Sun Nov  6 17:56:21 2016 Arthur Chaloin
*/
#include "my.h"
#include "bistro-matic.h"

int	check_actual(char *expr, int index)
{
  char	*actual;

  actual = my_strndup(expr + index, 1);
  return ((my_strstr(g_arithmetic.ope_high, actual) &&
	  my_strstr(g_arithmetic.ope_high, my_strndup(expr + index + 1, 1))) ||
	  (expr[index] == g_arithmetic.ops[OP_PAR_O] &&
	   (expr[index + 1] == g_arithmetic.ops[OP_PAR_C] ||
	    my_str_contain(g_arithmetic.ope_high, expr[index + 1]) != -1)) ||
	  (!my_strstr(g_arithmetic.ops, actual) &&
	   !my_strstr(g_arithmetic.base, actual)) ||
	  (my_str_contain(g_arithmetic.ope_low, expr[index]) != -1 &&
	   my_str_contain(g_arithmetic.ope_high, expr[index + 1]) != -1) ||
	  (my_str_contain(g_arithmetic.ops + 2, expr[index]) != -1 &&
	   expr[index + 1] == g_arithmetic.ops[OP_PAR_C]) ||
	  (my_str_contain(g_arithmetic.ope_high, expr[0]) != -1 ||
	   expr[0] == g_arithmetic.ops[OP_PAR_C]) || (expr[index] ==
	   g_arithmetic.ops[OP_PAR_C] &&
	   my_str_contain(g_arithmetic.ops + 1, expr[index + 1]) == -1 &&
	   expr[index + 1] != 0) || (expr[index + 1] ==
	   g_arithmetic.ops[OP_PAR_O] && my_strstr(
						g_arithmetic.base, actual)));
}

int	check_expr(char *expr)
{
  int	index;
  int	level;

  index = 0;
  level = 0;
  while (expr[index])
    {
      if (expr[index] == g_arithmetic.ops[OP_PAR_O])
	level += 1;
      if (expr[index] == g_arithmetic.ops[OP_PAR_C])
	level -= 1;
      if (check_actual(expr, index))
	return (EXIT_FAILURE);
      index += 1;
    }
  if (!my_strstr(g_arithmetic.base, my_strndup(expr + index - 1, 1)) &&
      expr[index - 1] != g_arithmetic.ops[OP_PAR_C])
    return (EXIT_FAILURE);
  return ((level == 0) ? EXIT_SUCCESS : EXIT_FAILURE);
}
