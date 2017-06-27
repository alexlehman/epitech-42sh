/*
** eval.c for 42sh in /Users/arthur/Documents/Dev/Epitech/PSU/PSU_2016_42sh/src/core/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Sun May 21 19:34:42 2017 Arthur Chaloin
** Last update Sun May 21 23:08:00 2017 Arthur Chaloin
*/
#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include "sh.h"
#include "calc.h"
#include "error.h"

static int	str_replace(char **str, int x, int y, char *replace)
{
  (*str)[x] = 0;
  if (replace)
    asprintf(str, "%s%s%s", *str, replace, *str + y);
  else
    {
      werror("Syntax error.", strndup(*str + x + 1, y - x), false);
      return (1);
    }
  return (0);
}

int	apply_math(char **command)
{
  int	index;
  int	index2;
  char	*var;

  index = 0;
  if (!strncmp(*command, "while", 5))
    return (0);
  while ((*command)[index])
    {
      index2 = 0;
      while ((*command)[index + index2] && (*command)[index + index2] != '$')
	index++;
      while ((*command)[index + index2] && (*command)[index + index2] != ' ')
	index2++;
      if ((*command)[index])
	{
	  var = eval(strndup(*command + index + 2, index2 - 3));
	  if (str_replace(command, index, index + index2, var))
	    return (1);
	}
      index += index2;
    }
  return (0);
}
