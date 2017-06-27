/*
** normalize.c for lexer in /home/arbona/CPool/CPool_bistro-matic/src/eval_expr/lexer/
**
** Made by Thomas Arbona
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Mon Oct 31 11:12:45 2016 Thomas Arbona
** Last update Fri Nov  4 11:22:59 2016 Arthur Chaloin
*/
#include "my.h"
#include "bistro-matic.h"

static void	shift_str(char **str, int index)
{
  while ((*str)[index] != '\0')
    {
      (*str)[index - 1] = (*str)[index];
      index += 1;
    }
  (*str)[index - 1] = '\0';
}

void	normalize_sign(char **str)
{
  int	index;

  index = 0;
  while ((*str)[index + 1] != '\0')
    {
      if ((*str)[index] == g_arithmetic.ops[OP_ADD] &&
	  !my_strstr(g_arithmetic.ope_low, my_strndup((*str) + index + 1, 1))
	  && (index == 0 || (*str)[index - 1] == g_arithmetic.ops[OP_PAR_O] ||
	  my_strstr(g_arithmetic.ope_high, my_strndup((*str) + index - 1, 1))))
	shift_str(str, index + 1);
      if (my_strstr(g_arithmetic.ope_low, my_strndup((*str) + index, 1)) &&
	  my_strstr(g_arithmetic.ope_low, my_strndup((*str) + index + 1, 1)))
	{
	  if ((*str)[index] == g_arithmetic.ops[OP_SUB] &&
	      (*str)[index + 1] == g_arithmetic.ops[OP_SUB])
	    (*str)[index] = g_arithmetic.ops[OP_ADD];
	  else if ((*str)[index] == g_arithmetic.ops[OP_ADD] &&
	      (*str)[index + 1] == g_arithmetic.ops[OP_SUB])
	    (*str)[index] = g_arithmetic.ops[OP_SUB];
	  shift_str(str, index + 2);
	}
      else
      	index += 1;
    }
}
