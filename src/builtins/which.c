/*
** where.c for 42sh in /Users/arthur/Documents/Dev/B2/PSU/PSU_2016_42sh/src/builtins/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Tue May  2 14:59:37 2017 Arthur Chaloin
** Last update Sun May 21 22:00:29 2017 Arthur Chaloin
*/
#include <stdio.h>
#include "sh.h"
#include "builtin.h"
#include "error.h"

int		builtin_which(t_sh *sh, char **argv)
{
  int		index;
  int		index2;
  bool		found;

  found = false;
  if (!argv[1])
    return (werror(E_MISSING_ARG, argv[0], false));
  index = 0;
  while (argv[++index])
    {
      index2 = -1;
      while (builtins[++index2].name &&
	     strcmp(builtins[index2].name, argv[index]));
      if (builtins[index2].name)
	{
	  printf("%s: shell built-in command.\n", argv[index]);
	  found = true;
	}
      else
	found = (char *)map_get(sh->bin, argv[index])
	  ? printf("%s\n", (char *)map_get(sh->bin, argv[index])) : 0;
      if (!found)
	werror(E_UNKNOWN_CMD, argv[index], false);
      }
  return (!found);
}
