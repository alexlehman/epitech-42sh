/*
** handling.c for 42sh in /Users/arthur/Documents/Dev/Epitech/PSU/PSU_2016_42sh/src/core/input/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Sun May 21 22:18:45 2017 Arthur Chaloin
** Last update Sun May 21 22:49:31 2017 Arthur Chaloin
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

static void	flush_input(char **input, int cursor)
{
  int		index;

  index = cursor - 1;
  while ((*input)[++index])
    write(1, "\033[1C", 4);
  index = -1;
  while ((*input)[++index])
    write(1, "\10\33[1P", 5);
}

static void	set_input(char **input, char buffer, int *cursor)
{
  char		*tmp;

  if (buffer == BACKSPACE && *cursor > 0)
    {
      tmp = strndup(*input, *cursor - 1);
      if (asprintf(input, "%s%s", tmp, *input + *cursor) == -1)
        werror("Fatal error", "42sh", true);
      (*cursor)--;
    }
  else if (buffer != BACKSPACE && buffer != '\t')
    {
      tmp = strndup(*input, *cursor);
      if (asprintf(input, "%s%c%s", tmp, buffer, *input + *cursor) == -1)
        werror("Fatal error", "42sh", true);
      (*cursor)++;
    }
}

void		update_input(char **input, char buffer, const int mode)
{
  int		index;
  static int	cursor = 0;

  if (!input)
    {
      cursor = mode;
      return;
    }
  flush_input(input, cursor);
  if (mode == I_SET_IPT)
    set_input(input, buffer, &cursor);
  else if (mode == I_SET_CURS)
    {
      if (buffer == 'D' && cursor > 0)
	cursor--;
      else if (buffer == 'C' && cursor < (int)strlen(*input))
	cursor++;
    }
  if (*input)
    {
      write(1, *input, strlen(*input));
      index = strlen(*input);
      while (--index >= cursor && index >= 0)
	write(1, "\033[1D", 4);
    }
}
