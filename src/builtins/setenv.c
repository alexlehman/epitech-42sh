/*
** setenv.c for mysh in /home/arthur/Documents/B1-Systeme_UNIX/PSU_2016_minishell1/src/builtins/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Mon Jan 16 22:29:46 2017 Arthur Chaloin
** Last update Fri Apr 28 22:26:55 2017 Arthur Chaloin
*/
#include <stdlib.h>
#include "sh.h"
#include "builtin.h"
#include "error.h"

static int	check_name(char *name)
{
  int		index;

  index = 1;
  if ((name[0] < 'a' || name[0] > 'z') &&
      (name[0] < 'A' || name[0] > 'Z'))
    {
      werror(E_BAD_BEGIN, "setenv", false);
      return (1);
    }
  while (name[index])
    {
      if ((name[index] < 'a' || name[index] > 'z') &&
	  (name[index] < 'A' || name[index] > 'Z') &&
	  (name[index] < '0' || name[index] > '9'))
	{
	  werror(E_BAD_NAME, "setenv", false);
	  return (1);
        }
      index++;
    }
  return (0);
}

int	builtin_setenv(__attribute__((unused))t_sh *sh, char **argv)
{
  if (!argv[1])
    builtin_env(NULL, NULL);
  else
    {
      if (check_name(argv[1]))
	return (1);
      setenv(argv[1], (argv[2]) ? argv[2] : "", true);
    }
  return (0);
}
