/*
** exit.c for mysh in /home/arthur/Documents/B1-Systeme_UNIX/PSU_2016_minishell1/src/builtins/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Wed Jan  4 16:49:23 2017 Arthur Chaloin
** Last update Wed May 10 17:28:08 2017 Arthur Chaloin
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "sh.h"
#include "my.h"

int		builtin_exit(t_sh *sh, char **argv)
{
  int		ret;

  if (!isatty(1))
    {
      if (argv[1])
	sh->ret = atoi(argv[1]);
      else
	sh->ret = 0;
    }
  else
    {
      write(1, "exit\n", 5);
      save_history(sh);
      end_gc();
      if (argv[1])
	ret = atoi(argv[1]);
      else
	ret = 0;
      exit((unsigned int)ret % 256);
    }
  return (0);
}
