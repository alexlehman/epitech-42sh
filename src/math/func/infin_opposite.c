/*
** infin_opposite.c for infin_opposite in /home/onehandedpenguin/CPool_bistro-matic/bonus/src/func/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Sat Nov  5 13:05:48 2016 Paul Laffitte
** Last update Sat Nov  5 13:22:01 2016 Paul Laffitte
*/
#include "my.h"
#include "bistro-matic.h"
#include "bonus.h"

char	*infin_opposite(char **argv)
{
  char	*tmp;
  if (argv[0][0] == g_arithmetic.ope_low[1])
    argv[0] = argv[0] + 1;
  else
    {
      if (!(tmp = malloc(sizeof(char) * (my_strlen(argv[0]) + 2))))
	exit_error(MALLOC_FAILED);
      tmp[0] = g_arithmetic.ope_low[1];
      tmp[1] = '\0';
      my_strcat(tmp, argv[0]);
      free(argv[0]);
      argv[0] = tmp;
    }
  return (argv[0]);
}
