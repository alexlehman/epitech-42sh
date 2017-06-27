/*
** while.c for 42sh in /home/arbona/tek1/PSU/PSU_2016_42sh
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Sun May 21 15:46:12 2017 Thomas ARBONA
** Last update Sun May 21 23:08:40 2017 Thomas ARBONA
*/
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include "sh.h"
#include "input.h"
#include "builtin.h"
#include "error.h"
#include "utils.h"

static int	while_handle_error(char **argv)
{
  if (argv[1] == NULL)
    return (werror("Too few arguments.", "while", 0));
  if (argv[1][0] != '(')
    return (werror("Expression Syntax.", "while", 0));
  return (0);
}

static int	while_read_full(t_sh *sh, char **buff)
{
  char  *line;

  *buff = "";
  line = NULL;
  if (isatty(0))
    write(1, "while? ", 7);
  while (get_input(sh, &line))
    {
      if (strstr(line, "end"))
	break;
      asprintf(buff, "%s%s\n", *buff, line);
      if (isatty(0))
	write(1, "while? ", 7);
    }
  return (0);
}

static void	while_exec_body(t_sh *sh, char **body)
{
  int		index;

  index = 0;
  while (body[index] != NULL)
    {
      sh_action(sh, body[index]);
      index += 1;
    }
}

int	builtin_while(t_sh *sh, char **argv)
{
  t_if	data;
  int	index;
  int	cursor;
  char	**body;

  if (while_handle_error(argv) == 1)
    return (1);
  data.cond = "";
  data.body = "";
  if (if_getcond_oneline(&data.cond, argv, &index, &cursor) == -1 ||
      argv[index + 1] == 0)
    return (werror("Syntax Error.", "while", 0));
  if (strcmp("then", argv[index + 1]) == 0)
    {
      while_read_full(sh, &data.body);
      body = strsplit(data.body, "\n");
    }
  else
    if_getbody_oneline(&data.body, argv, &index, &cursor);
  while ((data.cond[0] == '[' && sh_action(sh, data.cond) == 0) ||
	 (data.cond[0] != '[' && atoi(data.cond)))
    while_exec_body(sh, body);
  return (0);
}
