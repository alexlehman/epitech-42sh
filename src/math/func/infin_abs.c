/*
** infin_abs.c for infin_abs in /home/onehandedpenguin/CPool_bistro-matic/bonus/src/func/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Sat Nov  5 13:03:10 2016 Paul Laffitte
** Last update Sat Nov  5 13:25:50 2016 Paul Laffitte
*/
#include "my.h"
#include "bistro-matic.h"
#include "bonus.h"

char	*infin_abs(char **argv)
{
  if (argv[0][0] == g_arithmetic.ope_low[1])
    argv[0] = argv[0] + 1;
  return (argv[0]);
}
