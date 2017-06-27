/*
** func_error.c for bistro-matic in /home/arthur/Documents/Piscine/Projects/CPool_bistro-matic/bonus/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Fri Nov  4 18:35:09 2016 Arthur Chaloin
** Last update Sun Nov  6 20:19:19 2016 Arthur Chaloin
*/
#include "my.h"
#include "bistro-matic.h"
#include "bonus.h"
#include "error_bonus.h"

t_error_data	*init_error_cursors()
{
  t_error_data	*data;

  if (!(data = malloc(sizeof(t_error_data))))
    exit_error(MALLOC_FAILED);
  data->index = 0;
  data->lvl = 0;
  data->args_nb = 0;
  return (data);
}

void	check_args_nb(t_error_data *data, char *func)
{
  data->lvl = (func[data->index] == g_arithmetic.ops[OP_PAR_O]) ?
      data->lvl + 1 : data->lvl;
  data->lvl = (func[data->index] == g_arithmetic.ops[OP_PAR_C]) ?
      data->lvl - 1 : data->lvl;
  if (func[data->index] != g_arithmetic.ops[OP_SEP] &&
      func[data->index + 1] == g_arithmetic.ops[OP_SEP] && data->lvl == 0)
    data->args_nb += 1;
  else if (func[data->index] == g_arithmetic.ops[OP_SEP] &&
	   func[data->index + 1] == g_arithmetic.ops[OP_SEP])
    exit_error(SYNTAX_ERR);
  data->index += 1;
}

static int	check_syntax(char *func)
{
  t_error_data	*data;

  data = init_error_cursors();
  while (func[data->index] != g_arithmetic.ops[OP_PAR_O])
    data->index += 1;
  if (!(get_calc_func(my_strndup(func + 1, data->index - 1))))
    exit_error(SYNTAX_ERR);
  data->index += 1;
  data->name = get_calc_func(my_strndup(func + 1, data->index - 2))->name;
  while (func[data->index])
    check_args_nb(data, func);
  if (func[data->index - 2] != g_arithmetic.ops[OP_SEP] &&
      func[data->index - 2] != g_arithmetic.ops[OP_PAR_O])
    data->args_nb += 1;
  if (data->args_nb != get_calc_func(data->name)->nb_args)
    exit_error(SYNTAX_ERR);
  data->args = split_root_sep(my_strndup(func + my_strlen(data->name) + 2,
    my_strlen(func + my_strlen(data->name) + 2) - 1));
  data->index = 0;
  while (data->index < data->args_nb)
    {
      check_func(data->args[data->index]);
      data->index += 1;
    }
  return (EXIT_SUCCESS);
}

int	check_func(char *str)
{
  int	index;
  int	start;
  int	lvl;

  index = 0;
  while (str[index])
    {
      if (str[index] == g_arithmetic.ops[OP_FUNC])
	{
	  lvl = 1;
	  start = index;
          while (str[index] && str[index] != g_arithmetic.ops[OP_PAR_O])
            index += 1;
	  while (lvl != 0 && str[index] && str[++index])
	    update_level(&lvl, str[index]);
	  if (index == my_strlen(str) || str[index + 1] ==
	      g_arithmetic.ops[OP_FUNC] || check_syntax(my_strndup(str + start,
		index - start + 1)) || lvl != 0)
	    exit_error(SYNTAX_ERR);
	}
      index += 1;
    }
  return (EXIT_SUCCESS);
}
