/*
** lexer_util.c for eval_expr in /home/arthur/Documents/Piscine/CPool_evalexpr/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Thu Oct 27 14:28:48 2016 Arthur Chaloin
** Last update Fri Nov  4 11:21:03 2016 Arthur Chaloin
*/
#include <stdlib.h>
#include "my.h"
#include "bistro-matic.h"

void	update_level(int *level, char cursor)
{
  if (cursor == g_arithmetic.ops[OP_PAR_O])
    *level += 1;
  if (cursor == g_arithmetic.ops[OP_PAR_C])
    *level -= 1;
}

void	reset_lexer_cursors(t_cursors *cursors)
{
  cursors->one = 0;
  cursors->two = 0;
}

int		is_block(char *str)
{
  int		index;
  int		level;

  index = 0;
  level = 0;
  while (str[index])
    {
      update_level(&level, str[index]);
      if (level == 0 &&
	  (my_strstr(g_arithmetic.ope_low, my_strndup(str + index, 1)) ||
	   my_strstr(g_arithmetic.ope_high, my_strndup(str + index, 1))))
	return (0);
      index += 1;
    }
  return (1);
}

int	is_sign_block(char *str)
{
  if (my_strstr(g_arithmetic.ope_low, my_strndup(str, 1)) != NULL &&
      is_block(str + 1))
    return (1);
  return (0);
}

void	handle_block(char **str)
{
  if ((*str)[0] == g_arithmetic.ops[OP_ADD])
    *str += 1;
  if (!is_block(*str) || (*str)[0] != g_arithmetic.ops[OP_PAR_O])
    return;
  (*str)[my_strlen(*str) - 1] = '\0';
  *str += 1;
}
