/*
** set.c for 42sh in /Users/arthur/Documents/Dev/Epitech/PSU/PSU_2016_42sh/src/builtins/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Sun May 21 15:39:21 2017 Arthur Chaloin
** Last update Sun May 21 15:46:31 2017 Arthur Chaloin
*/
#include <stdlib.h>
#include "sh.h"
#include "builtin.h"
#include "utils.h"
#include "error.h"

static int	check_name(char *name)
{
  if ((name[0] < 'a' || name[0] > 'z') &&
      (name[0] < 'A' || name[0] > 'Z'))
    {
      werror(E_BAD_BEGIN, "set", false);
      return (1);
    }
  return (0);
}

int	builtin_set(__attribute__((unused))t_sh *sh, char **argv)
{
  int	index;
  int	ret;
  char	**tab;

  ret = 0;
  if (!argv[1])
    builtin_env(NULL, NULL);
  else
    {
      index = 0;
      while (argv[++index])
	{
	  if (check_name(argv[1]))
	    {
	      ret = 1;
	      continue;
	    }
	  ret = 0;
	  tab = lexer(strdup(argv[index]), (char *[]) {"=", NULL}, "\"\"''", true);
	  if (!tab || !tab[0])
	    return (1);
	  setenv(tab[0], (tab[1]) ? tab[1] : "", true);
	}
    }
  return (ret);
}
