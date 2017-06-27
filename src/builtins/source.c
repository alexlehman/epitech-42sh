/*
** source.c for mysh in /home/arthur/B2/PSU/PSU_2016_minishell2/bonus/src/builtins/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Mon Apr 10 16:09:59 2017 Arthur Chaloin
** Last update Sun May 21 21:40:05 2017 Arthur Chaloin
*/
#include <stdio.h>
#include <string.h>
#include "sh.h"
#include "error.h"
#include "my.h"

int		builtin_source(t_sh *sh, char **argv)
{
  FILE		*fd;
  char		*line;
  size_t	size;

  size = 0;
  line = NULL;
  if (argv[1])
    {
      if (!(fd = fopen(argv[1], "r")))
	{
	  werror(E_NOT_FOUND, "source", false);
	  return (1);
	}
      while (getline(&line, &size, fd) != -1)
	{
	  if (line[strlen(line) - 1] == '\n')
	    line[strlen(line) - 1] = 0;
	  if (line[0] && my_strncmp(line, "source", 6))
	    sh_action(sh, line);
	}
      fclose(fd);
    }
  return (0);
}
