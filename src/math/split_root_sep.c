/*
** get_func_elements.c for bonus in /home/arbona/CPool/CPool_bistro-matic/bonus/src/eval_func/
**
** Made by Thomas Arbona
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Sat Nov  5 15:46:52 2016 Thomas Arbona
** Last update Sat Nov  5 23:03:42 2016 Thomas Arbona
*/
#include "my.h"
#include "bistro-matic.h"
#include "bonus.h"

static void	push_element(char *expr,
			     char **elements,
			     int *index,
			     t_cursors *cursors)
{
  elements[*index] = my_strndup(expr + cursors->one,
    cursors->two - cursors->one);
  *index += 1;
  cursors->one = cursors->two + 1;
}

static int	count_elements(char *expr)
{
  int		count;
  int		index;

  count = 0;
  index = 0;
  while (expr[index] != '\0')
    {
      if (expr[index] == g_arithmetic.ops[OP_SEP])
	count += 1;
      index += 1;
    }
  return (count + 1);
}

char		**split_root_sep(char *expr)
{
  int		level;
  char		**elements;
  int		el_index;
  t_cursors	cursors;

  level = 0;
  el_index = 0;
  cursors.one = 0;
  cursors.two = 0;
  if (!(elements = malloc(sizeof(char *) * (count_elements(expr) + 1))))
    exit_error(MALLOC_FAILED);
  while (expr[cursors.two] != '\0')
    {
      update_level(&level, expr[cursors.two]);
      if (expr[cursors.two] == g_arithmetic.ops[OP_SEP] &&
	  level == 0)
	push_element(expr, elements, &el_index, &cursors);
      cursors.two += 1;
    }
  push_element(expr, elements, &el_index, &cursors);
  elements[el_index] = NULL;
  return (elements);
}
