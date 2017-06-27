/*
** if.c for 42sh in /home/arbona/tek1/PSU/PSU_2016_42sh/src
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Wed May 17 18:54:52 2017 Thomas ARBONA
** Last update Sun May 21 23:08:19 2017 Arthur Chaloin
*/
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "sh.h"
#include "builtin.h"
#include "input.h"
#include "my.h"

static int	if_handle_error(char **argv)
{
  if (argv[1] == NULL)
    {
      write(2, "if: Too few arguments.\n", 23);
      return (1);
    }
  if (argv[1][0] != '(')
    {
      write(2, "if: Expression Syntax.\n", 23);
      return (1);
    }
  return (0);
}

static int	if_handle_then(t_sh *sh, t_list *ifs)
{
  char		*buff;
  t_if		*curr;

  curr = (t_if*)ifs->front->data;
  if_read_full(sh, &buff);
  asprintf(&buff, "if (%s) then %s", curr->cond, buff);
  if (if_parse(ifs, buff) == -1)
    {
      write(2, "if: Syntax Error.\n", 18);
      return (-1);
    }
  return (0);
}

int		builtin_if(t_sh *sh, char **argv)
{
  t_list	*ifs;
  int		index;
  int		cursor;
  t_if		*curr;

  if (if_handle_error(argv) == 1)
    return (1);
  ifs = create_list(LINKED_LIST);
  curr = if_new("", "");
  push_back(ifs, (void*)curr);
  if (if_getcond_oneline(&curr->cond, argv, &index, &cursor) == -1 ||
      argv[index + 1] == 0)
    {
      write(2, "if: Syntax Error.\n", 18);
      return (1);
    }
  if (strcmp("then", argv[index + 1]) == 0)
    {
      if (if_handle_then(sh, ifs) == -1)
	return (1);
    }
  else
    if_getbody_oneline(&curr->body, argv, &index, &cursor);
  if_exec(sh, ifs);
  return (0);
}
