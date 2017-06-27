/*
** parser.c for mysh in /home/arthur/Documents/B1-Systeme_UNIX/PSU_2016_minishell1/src/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Tue Jan  3 17:07:33 2017 Arthur Chaloin
** Last update Sun May 21 22:04:09 2017 Arthur Chaloin
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "sh.h"
#include "command.h"
#include "input.h"
#include "parser.h"
#include "error.h"
#include "utils.h"

static void	read_command(t_sh *sh, char **command)
{
  printf("? ");
  fflush(stdout);
  get_input(sh, command);
}

int	command_parse(t_sh *sh, t_command *command, char *raw_command)
{
  int	ret;

  if (!strncmp(raw_command, "#!", 2))
    return (-1);
  command->start = NULL;
  while (strlen(raw_command) && raw_command[strlen(raw_command) - 1] == '\\')
    read_command(sh, &raw_command);
  command->raw = raw_command;
  if (!strsplit(raw_command, " \t") || !strsplit(raw_command, " \t")[0])
    return (0);
  ret = parser_separators(command);
  if (ret)
    return ((ret == 1) ? 1 : 0);
  if ((ret = parser_logic(&command->start)))
    return (ret);
  if (parser_pipes(&command->start)
      || parser_redirects(&command->start))
    return (1);
  if ((ret = check_ambigues(&command->start)))
    {
      werror((ret == 1) ? E_AMBIGU_IN : E_AMBIGU_OUT, NULL, false);
      return (1);
    }
  return (0);
}
