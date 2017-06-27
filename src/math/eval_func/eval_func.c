/*
** eval_func.c for bonus in /home/arbona/CPool/CPool_bistro-matic/bonus/eval_func/
**
** Made by Thomas Arbona
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Fri Nov  4 15:45:10 2016 Thomas Arbona
** Last update Sun Nov  6 18:13:11 2016 Thomas Arbona
*/
#include "my.h"
#include "bistro-matic.h"
#include "bonus.h"

static void	handle_func(int *func_level,
			    t_cursors *cursors,
			    char **expr)
{
  char	*func_result;

  *func_level -= 1;
  if (*func_level != 0)
    return;
  func_result = exec_func(
    my_strndup(*expr + cursors->one, cursors->two - cursors->one + 1));
  *expr = my_str_replace(*expr, cursors->one, cursors->two,
			 add_par(func_result));
  cursors->two = cursors->one;
}

char		*eval_func(char *expr)
{
  t_cursors	cursors;
  int		func_level;

  cursors.one = 0;
  cursors.two = 0;
  func_level = 0;
  while (expr[cursors.two] != '\0')
    {
      if (expr[cursors.two] == g_arithmetic.ops[OP_PAR_O] &&
	  cursors.one != cursors.two)
	func_level += 1;
      else if (expr[cursors.two] == g_arithmetic.ops[OP_PAR_C] &&
	       cursors.one != cursors.two)
	handle_func(&func_level, &cursors, &expr);
      else if (expr[cursors.two] == g_arithmetic.ops[OP_FUNC] &&
	       cursors.one == cursors.two)
	cursors.two += 1;
      if (cursors.one == cursors.two)
      	cursors.one += 1;
      cursors.two += 1;
    }
  return (expr);
}
