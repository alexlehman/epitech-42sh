/*
** history.c for mysh in /home/arthur/B1/PSU/PSU_2016_minish1_bonus/src/system/history/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Wed Jan 25 20:49:22 2017 Arthur Chaloin
** Last update Sun May 21 22:01:31 2017 Arthur Chaloin
*/
#define _GNU_SOURCE
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "sh.h"
#include "input.h"
#include "error.h"
#include "my.h"

void	save_history(t_sh *sh)
{
  int	fd;
  char	*tmp;

  tmp = NULL;
  asprintf(&tmp, "%s/.42sh_history", getenv("HOME"));
  if ((fd = open(tmp, O_CREAT | O_WRONLY, 00644)) == -1)
    {
      werror("can't save history", "42sh", false);
      return;
    }
  while (sh->history->prev)
    sh->history = sh->history->prev;
  while (sh->history)
    {
      dprintf(fd, "%s\n", sh->history->command);
      sh->history = sh->history->next;
    }
  close(fd);
}

void			set_history(t_sh *sh, char *command)
{
  t_history		*new;

  GC_USE(0);
  new = galloc(sizeof(t_history));
  new->command = strdup(command);
  new->next = NULL;
  if (sh->history)
    {
      new->prev = sh->history;
      sh->history->next = new;
    }
  else
    new->prev = NULL;
  sh->history = new;
  GC_USE(1);
}

void			history(t_sh *sh, int entry, char **command)
{
  int			index;
  static t_history	*actual = NULL;
  static int		reset = 1;

  if (!entry)
    {
      actual = sh->history;
      reset = 1;
    }
  else if (entry < 0 && actual && actual->prev && reset)
    reset = 0;
  else if (entry < 0 && actual && actual->prev)
    actual = actual->prev;
  else if (entry > 0 && actual && actual->next)
    actual = actual->next;
  if (actual && entry)
    {
      index = -1;
      while ((*command)[++index])
	write(1, "\10\33[1P", 5);
      asprintf(command, "%s", actual->command);
      write(1, *command, strlen(*command));
      update_input(NULL, 0, 0);
      update_input(NULL, 0, strlen(*command));
    }
}
