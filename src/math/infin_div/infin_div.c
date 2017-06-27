/*
** infin_div.c for bistro-matic in /home/arthur/Documents/Piscine/Projects/CPool_bistro-matic/src/infin_div/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Wed Nov  2 15:41:14 2016 John Doe
** Last update Fri Nov  4 11:54:58 2016 Arthur Chaloin
*/
#include "my.h"
#include "bistro-matic.h"

void	set_rest(t_division_data *data)
{
  my_memset(data->result->rest + my_strlen(data->result->rest),
	    data->len_divid + 1 - my_strlen(data->result->rest), 0);
  data->result->rest[my_strlen(data->result->rest)]
    = data->dividend[data->index];
}

void	add_minus(t_division_data *data)
{
  char	*new;

  if (data->result_is_neg)
    {
      if (!(new = malloc(sizeof(char) *
			 (my_strlen(data->result->quotient) + 2))))
	exit_error(MALLOC_FAILED);
      new[0] = g_arithmetic.ops[OP_SUB];
      my_strcpy(new + 1, data->result->quotient);
      data->result->quotient = new;
    }
  if (data->dividend_isneg)
    {
      if (!(new = malloc(sizeof(char) * (my_strlen(data->result->rest) + 2))))
	exit_error(MALLOC_FAILED);
      new[0] = g_arithmetic.ops[OP_SUB];
      my_strcpy(new + 1, data->result->rest);
      data->result->rest = new;
    }
}

void	get_result_sign(t_division_data *data)
{
  int	entered;

  entered = 0;
  if (data->dividend[0] == g_arithmetic.ops[OP_SUB])
    {
      data->dividend_isneg = 1;
      data->dividend += 1;
      data->result_is_neg = !data->result_is_neg;
      entered += 1;
    }
  if (data->divisor[0] == g_arithmetic.ops[OP_SUB])
    {
      data->divisor += 1;
      data->result_is_neg = !data->result_is_neg;
      data->len_divid += 1;
      entered += 1;
    }
  if (entered == 2)
    data->len_divid -= 2;
}

t_division_data		*init_div_data(char *n1, char *n2)
{
  t_division_data	*data;

  if (!(data = malloc(sizeof(t_division_data))))
    exit_error(MALLOC_FAILED);
  data->dividend = n1;
  data->divisor = n2;
  data->index = 0;
  data->len_divid = my_strlen(data->dividend);
  data->flag_div = 1;
  data->dividend_isneg = 0;
  data->result_is_neg = 0;
  if (!(data->result = malloc(sizeof(t_div_result))))
    exit_error(MALLOC_FAILED);
  if (!(data->result->rest = malloc(sizeof(char) * (data->len_divid + 1))))
    exit_error(MALLOC_FAILED);
  my_memset(data->result->rest, data->len_divid + 1, 0);
  if (!(data->result->quotient = malloc(sizeof(char) * (data->len_divid + 1))))
    exit_error(MALLOC_FAILED);
  my_memset(data->result->quotient, data->len_divid + 1, 0);
  return (data);
}

t_div_result		*infin_div(char *n1, char *n2)
{
  t_division_data	*data;

  data = init_div_data(n1, n2);
  get_result_sign(data);
  while (data->index < data->len_divid)
    {
      set_rest(data);
      data->result->quotient[data->index] = g_arithmetic.base[0];
      while (max_nb(data->result->rest, data->divisor) && data->flag_div)
	{
	  data->tmp = my_sub(data->result->rest, data->divisor);
	  if (max_nb(data->tmp, my_strndup(g_arithmetic.base, 1)))
	    my_strcpy(data->result->rest, data->tmp);
	  if (!max_nb(data->tmp, data->divisor))
	    data->flag_div = 0;
	  data->result->quotient[data->index] =
	    g_arithmetic.base[my_str_contain(g_arithmetic.base,
			    data->result->quotient[data->index]) + 1];
	}
      data->index += 1;
      data->flag_div = 1;
    }
  add_minus(data);
  data->result->quotient[data->len_divid] = '\0';
  return (data->result);
}
