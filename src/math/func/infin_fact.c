/*
** infin_fact.c for bistro-matic in /home/arthur/Documents/Piscine/Projects/CPool_bistro-matic/bonus/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Thu Nov  3 11:03:41 2016 John Doe
** Last update Sun Nov  6 15:40:05 2016 Paul Laffitte
*/
#include "my.h"
#include "bistro-matic.h"
#include "bonus.h"

char	*infin_fact(char **agrv)
{
  char	*result;
  char	*fact;
  char	*one;
  int	int_fact;
  int	i;

  one = convert_base("1", "0123456789", g_arithmetic.base);
  result = my_strdup(one);
  fact = my_strdup(one);
  int_fact = my_getnbr(agrv[0]);
  if (int_fact < 0)
    exit_error(FACT_NEG);
  i = 0;
  while (i < int_fact)
    {
      result = my_mul(result, fact);
      fact = my_add(fact, one);
      i += 1;
    }
  return (result);
}
