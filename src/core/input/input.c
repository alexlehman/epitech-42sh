/*
** input.c for 42sh in /Users/arthur/Documents/Dev/B2/PSU/PSU_2016_42sh/src/core/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Tue May  2 17:10:38 2017 Arthur Chaloin
** Last update Sun May 21 22:18:27 2017 Arthur Chaloin
*/
#define _GNU_SOURCE
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "input.h"
#include "complete.h"
#include "utils.h"
#include "error.h"
#include "sh.h"

static int	handle_buffer(t_sh *sh, char **input, char buffer)
{
  if (buffer == 12)
    return (1);
  else if (buffer == ESCAPE)
    {
      read(0, &buffer, 1);
      read(0, &buffer, 1);
      if (buffer == 'A')
        history(sh, -1, input);
      if (buffer == 'B')
        history(sh, 1, input);
      else if (buffer == 'C' || buffer == 'D')
        update_input(input, buffer, I_SET_CURS);
    }
  else
    {
      if (buffer == '\t')
        auto_complete(sh, input);
      update_input(input, buffer, I_SET_IPT);
    }
  return (0);
}

static char	*get_user_input(t_sh *sh)
{
  char		buffer;
  char		*input;

  buffer = 0;
  if (!(input = malloc(sizeof(char))))
    exit(84);
  *input = '\0';
  set_read_mode(1);
  update_input(NULL, 0, 0);
  while (read(0, &buffer, 1) && buffer != '\n')
    {
      if (handle_buffer(sh, &input, buffer))
	return (strdup("clear"));
    }
  set_read_mode(0);
  write(1, "\n", 1);
  return (input);
}

int		get_input(t_sh *sh, char **buff)
{
  size_t	size;

  size = 0;
  if (!isatty(STDIN_FILENO))
    {
      if (getline(buff, &size, stdin) == -1)
	return (0);
      (*buff)[strlen(*buff) - 1] = 0;
    }
  else
    {
      if (!(*buff = get_user_input(sh)))
	return (0);
    }
  if ((*buff)[0])
    {
      set_history(sh, *buff);
      history(sh, 0, NULL);
    }
  return (1);
}
