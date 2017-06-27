/*
** karatsuba.c for karatsuba in /home/arbona/CPool/CPool_bistro-matic/src/karatsuba/
**
** Made by Thomas Arbona
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Nov  1 11:40:55 2016 Thomas Arbona
** Last update Fri Nov  4 12:17:56 2016 Arthur Chaloin
*/
#include "my.h"
#include "bistro-matic.h"

static char	*init_mul(char **nb1, char **nb2, int *len)
{
  char		*result;

  if ((*nb1)[1] == '\0')
    my_swapstr(nb1, nb2);
  *len = my_strlen(*nb1);
  (*nb2)[0] = my_str_contain(g_arithmetic.base, (*nb2)[0]);
  if (!(result = malloc(sizeof(char) * ((*len) + 2))))
    exit_error(MALLOC_FAILED);
  result[(*len) + 1] = '\0';
  return (result);
}

char		*multiply(char *nb1, char *nb2)
{
  char		*result;
  int		len;
  int		curr;
  int		retained;
  int		tmp;

  retained = 0;
  result = init_mul(&nb1, &nb2, &len);
  curr = len;
  while (curr != 0)
    {
      tmp = my_str_contain(g_arithmetic.base, nb1[curr - 1])
	  * nb2[0] + retained;
      retained = tmp / g_arithmetic.len_base;
      result[curr] = g_arithmetic.base[tmp % g_arithmetic.len_base];
      curr -= 1;
    }
  result[curr] = g_arithmetic.base[retained];
  nb2[0] = g_arithmetic.base[(int)nb2[0]];
  if (result[0] == g_arithmetic.base[0])
    result += 1;
  return (result);
}

char	*set_neg(char *x)
{
  char	*result;

  if (!(result = malloc(sizeof(char) * (my_strlen(x) + 2))))
    exit_error(MALLOC_FAILED);
  my_strcpy(result + 1, x);
  result[0] = g_arithmetic.ops[OP_SUB];
  return (result);
}

char			*karatsuba(char *x, char *y)
{
  t_karatsuba_data	data;

  data.isneg = 0;
  data.isneg = krtsb_del_sign(&x, data.isneg);
  data.isneg = krtsb_del_sign(&y, data.isneg);
  if (MIN(my_strlen(x), my_strlen(y)) <= 1)
    return ((data.isneg) ? set_neg(multiply(x, y)) : multiply(x, y));
  data.n = MAX(my_strlen(x), my_strlen(y)) / 2;
  split(x, data.n, &data.a, &data.b);
  split(y, data.n, &data.c, &data.d);
  data.ac = karatsuba(data.a, data.c);
  data.bd = karatsuba(data.b, data.d);
  data.ad_p_bc = karatsuba(my_add(data.a, data.b), my_add(data.c, data.d));
  data.ad_p_bc = my_sub(data.ad_p_bc, data.ac);
  data.ad_p_bc = my_sub(data.ad_p_bc, data.bd);
  data.result = shift_nb(data.ac, 2 * data.n);
  data.result = my_add(data.result, shift_nb(data.ad_p_bc, data.n));
  data.result = my_add(data.result, data.bd);
  return ((data.isneg) ? set_neg(data.result) : data.result);
}
