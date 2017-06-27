/*
** unsetenv.c for mysh in /home/arthur/Documents/B1-Systeme_UNIX/PSU_2016_minishell1/src/builtins/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Mon Jan 16 22:29:37 2017 Arthur Chaloin
** Last update Fri Apr 28 22:03:47 2017 Arthur Chaloin
*/
#include <stdlib.h>
#include "sh.h"
#include "error.h"

int	builtin_unsetenv(__attribute__((unused))t_sh *sh, char **argv)
{
  if (!argv[1])
    {
      werror(E_MISSING_ARG, "unsetenv", false);
      return (1);
    }
  else
    unsetenv(argv[1]);
  return (0);
}
