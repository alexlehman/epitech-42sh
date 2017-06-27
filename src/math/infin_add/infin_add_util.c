/*
** calc_data.c for addInf in /home/arbona/CPool/CPool_infinadd
**
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
**
** Started on  Mon Oct 24 18:59:29 2016 Thomas Arbona
** Last update Fri Nov  4 11:30:41 2016 Arthur Chaloin
*/
#include "my.h"
#include "bistro-matic.h"

int	init_calc_data(t_calc_data *data, char *nb)
{
  data->isneg = 0;
  data->retained = 0;
  data->length = my_strlen(nb);
  data->cursor = data->length - 1;
  data->iterator = 0;
  if (!(data->result = malloc(sizeof(char) * (data->length + 3))))
    exit_error(MALLOC_FAILED);
  return (0);
}

void	delete_sign(char *nb1, char *nb2)
{
  if (nb1[0] == g_arithmetic.ops[OP_SUB])
    nb1[0] = g_arithmetic.base[0];
  if (nb2[0] == g_arithmetic.ops[OP_SUB])
    nb2[0] = g_arithmetic.base[0];
}
