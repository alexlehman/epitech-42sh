/*
** main.c for addInf in /home/arbona/CPool/CPool_infinadd
**
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
**
** Started on  Mon Oct 24 09:44:09 2016 Thomas Arbona
** Last update Fri Nov  4 12:18:37 2016 Arthur Chaloin
*/
#include "my.h"
#include "bistro-matic.h"

static char	*finish(t_calc_data *data)
{
  if (data->retained)
    data->result[data->iterator++] = g_arithmetic.base[data->retained];
  data->cursor = data->iterator - 1;
  while (data->result[data->cursor] == g_arithmetic.base[0] &&
	 data->cursor > 0)
    data->cursor -= 1;
  data->cursor += 1;
  data->result[data->cursor] =
    (!(data->cursor == 1 &&
       data->result[data->cursor - 1] == g_arithmetic.base[0]) && data->isneg)
      ? g_arithmetic.ops[OP_SUB] : '\0';
  data->result[++data->cursor] = '\0';
  return (my_revstr(data->result));
}

static char	*add(char *n1, char *n2)
{
  t_calc_data	data;

  if (init_calc_data(&data, n1) == 84)
    return (NULL);
  data.isneg = (n1[0] == g_arithmetic.ops[OP_SUB]);
  delete_sign(n1, n2);
  while (data.cursor >= 0)
    {
      if (n1[data.cursor] != g_arithmetic.ops[OP_SUB])
        {
	  data.curr = my_str_contain(g_arithmetic.base, n1[data.cursor]);
	  data.curr += my_str_contain(g_arithmetic.base, n2[data.cursor]);
	  data.curr += data.retained;
        }
      else
	data.curr = g_arithmetic.base[data.retained];
      data.retained = (data.curr >= g_arithmetic.len_base);
      data.result[data.iterator] =
	g_arithmetic.base[data.curr % g_arithmetic.len_base];
      data.iterator += 1;
      data.cursor -= 1;
    }
  data.result[data.iterator] = '\0';
  return (finish(&data));
}

static void	init_sub(char **n1, char **n2, t_calc_data *data)
{
  init_calc_data(data, *n1);
  if (!max_abs(*n1, *n2))
    my_swapstr(n1, n2);
  data->isneg = ((*n1)[0] == g_arithmetic.ops[OP_SUB]);
  delete_sign(*n1, *n2);
}

static char	*sub(char *n1, char *n2)
{
  t_calc_data	data;
  int		is_ret;

  is_ret = 0;
  init_sub(&n1, &n2, &data);
  while (data.cursor >= 0)
    {
      data.curr = my_str_contain(g_arithmetic.base, n1[data.cursor]);
      if (data.curr < my_str_contain(g_arithmetic.base, n2[data.cursor])
	  + data.retained)
	{
	  data.curr += g_arithmetic.len_base;
	  is_ret = 1;
	}
      data.curr -= my_str_contain(g_arithmetic.base, n2[data.cursor]) +
	      data.retained;
      data.retained = (is_ret);
      is_ret = 0;
      data.result[data.iterator] = g_arithmetic.base[data.curr];
      data.iterator += 1;
      data.cursor -= 1;
    }
  data.result[data.iterator] = '\0';
  return (finish(&data));
}

char	*infin_add(char *nb1, char *nb2)
{
  char	*result;

  normalize(&nb1, &nb2);
  result = ((nb1[0] == g_arithmetic.ops[OP_SUB]) ^
	    (nb2[0] == g_arithmetic.ops[OP_SUB]))
    ? sub(nb1, nb2)
    : add(nb1, nb2);
  return (result);
}
