/*
** complete.c for mysh in /home/arthur/B2/PSU/PSU_2016_minishell2/bonus/src/core/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Fri Apr  7 13:48:22 2017 Arthur Chaloin
** Last update Sat May 20 00:26:12 2017 Arthur Chaloin
*/
#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "sh.h"
#include "builtin.h"
#include "input.h"
#include "complete.h"
#include "parser.h"
#include "utils.h"
#include "my.h"

static int	tablen(char **tab)
{
  int		count;

  count = -1;
  while (tab[++count]);
  return (count);
}

void		complete(char **cmd, char *last)
{
  int		index;

  index = -1;
  while ((*cmd)[++index]);
  while (--index >= 0 && (*cmd)[index] != ' ' && (*cmd)[index] != '/');
  (*cmd)[index + 1] = 0;
  asprintf(cmd, "%s%s", *cmd, last);
}

int	match(char *s1, char *s2)
{
  if (*s1 == *s2)
    {
      if (*s1 == 0)
	return (1);
      return (match(s1 + 1, s2 + 1));
    }
  else if (*s2 == '*')
    {
      if (*s1 != 0)
	return (match(s1 + 1, s2) || match(s1, s2 + 1));
      return (match(s1, s2 + 1));
    }
  return (0);
}

static t_list	*complete_bin(t_sh *sh, char **cmd)
{
  int		index;
  char		*tmp;
  t_list	*list;
  t_list_elem	*cursor;

  index = -1;
  list = create_list(LINKED_LIST);
  while (builtins[++index].name)
    {
      tmp = NULL;
      asprintf(&tmp, "%s*", *cmd);
      if (match(builtins[index].name, tmp))
	push_back(list, builtins[index].name);
    }
  cursor = map_get_all(sh->bin)->front;
  while (cursor)
    {
      tmp = NULL;
      asprintf(&tmp, "%s*", *cmd);
      if (match(((t_map_item *)cursor->data)->key, tmp))
	push_back(list, ((t_map_item *)cursor->data)->key);
      cursor = cursor->next;
    }
  return (list);
}

void		auto_complete(t_sh *sh, char **cmd)
{
  int     	index;
  char		**split;
  t_list	*list;

  split = strsplit(*cmd, " \t|><;&");
  if (!split || !split[0])
    return;
  if (tablen(split) == 1)
    list = complete_bin(sh, cmd);
  else
    list = complete_dir(&split[tablen(split) - 1]);
  index = (list->size == 1) ? (int)strlen(*cmd) - 1 : -1;
  if (!list->size)
    return;
  else if (list->size == 1)
    complete(cmd, list->front->data);
  else
    select_op(cmd, list);
  update_input(NULL, 0, strlen(*cmd));
  while (++index < (int)strlen(*cmd))
    write(1, "\033[1C", 4);
}
