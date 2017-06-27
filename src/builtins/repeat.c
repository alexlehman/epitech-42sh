/*
** repeat.c for 42sh in /home/antiaskid/Documents/B2/PSU/PSU_2016_42sh/src/builtins/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Wed May 17 16:17:28 2017 Antoine Briaux
** Last update Sun May 21 23:08:44 2017 Arthur Chaloin
*/
#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include "sh.h"
#include "builtin.h"
#include "error.h"

static char 	*create_command(char **argv)
{
  int		i;
  char 		*command;

  i = 1;
  command = NULL;
  asprintf(&command, "%s", argv[++i]);
  while (argv[++i])
    asprintf(&command, "%s %s", command, argv[i]);
  return (command);
}

int 			builtin_repeat(t_sh *sh, char **argv)
{
  int			i;
  long int	nb_repeat;
  int 		return_value;
  char 		*command;

  if (!argv[1] || !argv[2])
    {
      werror(E_MISSING_ARG, "repeat", false);
      return (1);
    }
  nb_repeat = strtol(argv[1], &argv[1], 10);
  if (*argv[1] != '\0')
    {
      werror(E_BADLY_NB, "repeat", false);
      return (1);
    }
  i = 0;
  command = create_command(argv);
  while (i++ < nb_repeat)
    return_value = sh_action(sh, command);
  if (command)
    free(command);
  return (return_value);
}
