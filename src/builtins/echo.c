/*
** echo.c for 42sh in /Users/arthur/Documents/Dev/B2/PSU/PSU_2016_42sh/src/builtins/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Fri Apr 28 21:55:39 2017 Arthur Chaloin
** Last update Sat May 20 00:46:43 2017 Arthur Chaloin
*/
#include <unistd.h>
#include <string.h>
#include "sh.h"
#include "builtin.h"

int	builtin_echo(__attribute__((unused))t_sh *sh, char **argv)
{
  int	index;
  bool	newline;

  if (!argv[1])
    return (write(1, "\n", 1), 0);
  newline = strcmp(argv[1], "-n");
  index = !newline;
  while (argv[++index])
    {
      write(1, argv[index], strlen(argv[index]));
      if (argv[index + 1])
	write(1, " ", 1);
      else
	{
	  if (newline)
	    write(1, "\n", 1);
	}
    }
  return (0);
}
