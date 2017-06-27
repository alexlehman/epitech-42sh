/*
** alias.c for mysh in /home/arthur/B2/PSU/PSU_2016_minishell2/bonus/src/builtins/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Tue Apr 11 12:38:02 2017 Arthur Chaloin
** Last update Sun May 21 23:07:53 2017 Arthur Chaloin
*/
#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sh.h"
#include "utils.h"
#include "alias.h"
#include "error.h"
#include "my.h"

static int	get_pos(int pos, char *str)
{
  int		count;
  int		index;

  count = 0;
  index = 0;
  if (!pos)
    return (0);
  while (str[++index] && count < pos)
    {
      if (str[index] == ' ' && str[index - 1] != ' ')
	count++;
    }
  return (index);
}

static char	*str_replace(char *str, int x, int y, char *replace)
{
  str[x] = 0;
  asprintf(&str, "%s%s%s", str, replace, (str + y) ? str + y : "");
  return (str);
}

void		apply_alias(t_sh *sh, char **command)
{
  int		index2;
  char		**tab;
  t_list_elem	*elem;
  t_alias	*tmp;

  elem = sh->alias->front;
  while (elem)
    {
      tmp = (t_alias *)elem->data;
      tab = lexer(strdup(*command), (char *[]) {" ", "\t", NULL},
		  "\"\"''", false);
      index2 = -1;
      while (tab[++index2])
	{
	  if (!strcmp(tab[index2], tmp->alias))
	    *command = str_replace(*command, get_pos(index2, *command),
				   get_pos(index2, *command) +
				   strlen(tmp->alias), tmp->full);
	}
      elem = elem->next;
    }
}

static int	find_alias(t_sh *sh, char *name)
{
  t_list_elem	*cursor;
  t_alias	*tmp;

  cursor = sh->alias->front;
  while (cursor)
    {
      tmp = (t_alias *)cursor->data;
      if (!strcmp(name, tmp->alias))
	printf("%s\t(%s)\n", tmp->alias, tmp->full);
      cursor = cursor->next;
    }
  return (1);
}

int		builtin_alias(t_sh *sh, char **argv)
{
  int		index;
  t_alias	*new;
  t_list_elem	*cursor;

  if (!argv[1])
    {
      cursor = sh->alias->front;
      while (cursor)
	{
	  printf("%s\t(%s)\n", ((t_alias *)cursor->data)->alias,
		 ((t_alias *)cursor->data)->full);
	  cursor = cursor->next;
	}
      return (0);
    }
  else if (!argv[2])
    return (find_alias(sh, argv[1]));
  new = galloc(sizeof(t_alias));
  new->alias = argv[1];
  index = 2;
  asprintf(&new->full, "%s", argv[index]);
  while (argv[++index])
    asprintf(&new->full, "%s %s", new->full, argv[index]);
  push_back(sh->alias, new);
  return (0);
}
