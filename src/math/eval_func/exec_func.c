/*
** exec_func.c for bonus in /home/arbona/CPool/CPool_bistro-matic/bonus/eval_func/
**
** Made by Thomas Arbona
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Fri Nov  4 18:32:31 2016 Thomas Arbona
** Last update Sun Nov  6 01:42:12 2016 Thomas Arbona
*/
#include "my.h"
#include "bistro-matic.h"
#include "bonus.h"

t_calc_func	*get_calc_func(char *name)
{
  int		index;

  index = 0;
  while (g_calc_func[index].name != NULL)
    {
      if (my_strcmp(g_calc_func[index].name, name) == 0)
	return (&g_calc_func[index]);
      index += 1;
    }
  return (NULL);
}

char		*exec_func(char *func)
{
  int		index;
  char		*func_name;
  char		**func_args;
  t_calc_func	*calc_func;

  index = 0;
  func += 1;
  while (func[index] != g_arithmetic.ops[OP_PAR_O])
    index += 1;
  func_name = my_strndup(func, index);
  if (!(calc_func = get_calc_func(func_name)))
    exit_error(UNDEFINED_FUNC);
  func += index + 1;
  func[my_strlen(func) - 1] = '\0';
  func_args = split_root_sep(func);
  index = 0;
  while (index < calc_func->nb_args)
    {
      func_args[index] = handle_expr(func_args[index]);
      index += 1;
    }
  return (calc_func->func(func_args));
}
