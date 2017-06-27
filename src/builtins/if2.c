/*
** if2.c for 42sh in /home/arbona/tek1/PSU/PSU_2016_42sh
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Sat May 20 19:29:12 2017 Thomas ARBONA
** Last update Sun May 21 23:08:21 2017 Arthur Chaloin
*/
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "sh.h"
#include "builtin.h"
#include "input.h"
#include "my.h"

int      if_getbody_oneline(char **body, char **argv,
			    int *index, int *cursor)
{
  *cursor += 1;
  while (argv[*index])
    {
      asprintf(body, "%s %s", *body, argv[*index] + *cursor);
      *cursor = 0;
      *index += 1;
    }
  return (0);
}

int	if_getcond_oneline(char **cond, char **argv,
			    int *index, int *cursor)
{
  int	depth;
  char	*tmp;

  *index = 0;
  depth = 0;
  while (argv[++(*index)])
    {
      *cursor = -1;
      while (argv[*index][++(*cursor)] != 0)
	{
	  depth += (argv[*index][*cursor] == '(') ? 1
	    : (argv[*index][*cursor] == ')') ? -1 : 0;
	  if (depth == 0)
	    break;
	}
      tmp = strndup(argv[*index], *cursor + 1);
      asprintf(cond, "%s %s", *cond, tmp);
      free(tmp);
      if (argv[*index][*cursor] != 0)
	break;
    }
  tmp = strndup(*cond + 2, strlen(*cond) - 3);
  free(*cond);
  *cond = tmp;
  return (depth != 0 || argv[*index][*cursor + 1] != 0 ? -1 : 0);
}

t_if    *if_new(char *cond, char *body)
{
  t_if  *new;

  if (!(new = malloc(sizeof(t_if))))
    return (NULL);
  new->cond = cond;
  new->body = body;
  return (new);
}

void    if_goto_nextword(char *buff, int *cursor)
{
  while (buff[*cursor] == ' ' ||
	          buff[*cursor] == '\n' ||
	 buff[*cursor] == '\t')
    *cursor += 1;
}

int     if_read_full(t_sh *sh, char **buff)
{
  char  *line;

  *buff = "";
  line = NULL;
  if (isatty(0))
    write(1, "if? ", 4);
  while (get_input(sh, &line))
    {
      asprintf(buff, "%s%s\n", *buff, line);
      if (strstr(line, "endif"))
	break;
      if (isatty(0))
	write(1, "if? ", 4);
    }
  return (0);
}
