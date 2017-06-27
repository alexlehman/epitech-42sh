/*
** infin_pow.c for bistro-matic in /home/onehandedpenguin/CPool_bistro-matic/bonus/infin_pow/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Wed Nov  2 16:18:02 2016 Paul Laffitte
** Last update Sun Nov  6 20:53:50 2016 Paul Laffitte
*/
#include "my.h"
#include "bistro-matic.h"
#include "bonus.h"

static char	*infin_pow_rec(char *nb, int p)
{
  if (p == 0)
    return (my_strndup(g_arithmetic.base + 1, 1));
  if (p == 1)
    return (nb);
  if (p == 2)
    return (my_mul(nb, my_strdup(nb)));
  if (p % 2 == 0)
    return (infin_pow_rec(infin_pow_rec(nb, 2), p / 2));
  if (p % 2 == 1)
    return (my_mul(nb, infin_pow_rec(my_mul(nb, my_strdup(nb)), (p - 1) / 2)));
  return (my_strndup(g_arithmetic.base, 1));
}

char	*infin_pow(char **argv)
{
  return (infin_pow_rec(argv[0], my_getnbr_base(argv[1], g_arithmetic.base)));
}
