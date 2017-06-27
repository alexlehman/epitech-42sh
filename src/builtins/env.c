/*
** env.c for mysh in /home/arthur/Documents/B1-Systeme_UNIX/PSU_2016_minishell1/src/builtins/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Mon Jan 16 21:57:20 2017 Arthur Chaloin
** Last update Sun May 21 23:08:12 2017 Arthur Chaloin
*/
#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include "sh.h"
#include "calc.h"
#include "error.h"
#include "my.h"

static int	an(char c)
{
  return ((c >= '0' && c <= '9')
	  || (c >= 'a' && c <= 'z')
	  || (c >= 'A' && c <= 'Z'));
}

static char	*str_replace(char *str, int x, int y, char *replace)
{
  if (replace)
    asprintf(&str, "%s%s%s", strndup(str, x), replace, str + y);
  else
    {
      werror("Undefined variable.", strndup(str + x + 1, y - x - 1), false);
      return (NULL);
    }
  return (str);
}

int	apply_env(char **command)
{
  int	index, index2;
  char	*var;

  index = 0;
  if (!strncmp("while", *command, 5))
    return (0);
  while ((*command)[index])
    {
      index2 = 0;
      while ((*command)[index + index2] && (*command)[index + index2] != '$')
	index++;
      if (!(*command)[index + index2])
	return (0);
      while ((*command)[index + ++index2] && an((*command)[index + index2]));
      if (!(*command)[index])
	return (0);
      if (*(*command + index + 1) != '(')
	{
	  var = getenv(strndup(*command + index + 1, index2 - 1));
	  if (!(*command = str_replace(*command, index, index + index2, var)))
	    return (1);
	}
      index += (*(*command + index + 1) != '(') ? index2 : 1;
    }
  return (0);
}

int	builtin_env(__attribute__((unused))t_sh *sh,
		    __attribute__((unused))char **argv)
{
  int	index;

  index = -1;
  while (environ[++index])
    {
      write(1, environ[index], strlen(environ[index]));
      write(1, "\n", 1);
    }
  return (0);
}
