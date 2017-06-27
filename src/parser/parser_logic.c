/*
** parser_pipe.c for mysh in /home/arthur/B2/PSU/PSU_2016_minishell2/src/parser/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Wed Apr  5 19:43:26 2017 Arthur Chaloin
** Last update Sun May 21 22:09:56 2017 Arthur Chaloin
*/
#include <unistd.h>
#include <stdlib.h>
#include "command.h"
#include "parser.h"
#include "error.h"
#include "utils.h"

static int	tablen(char **tab)
{
  int		index;

  index = -1;
  while (tab[++index]);
  return (index);
}

static void	add_logical(t_node **actual, t_node **start, char **data,
			    char *type)
{
  insert_node(actual, type, NULL, 1);
  if (!*start)
    *start = *actual;
  else
    *actual = (*actual)->right;
  insert_node(actual, NULL, data, 0);
}

static int	upgrade_logical(t_node **node)
{
  int		index;
  char		**tab;
  t_node	*actual;
  t_node	*start;

  if ((index = check_logic_syntax(node)))
    return (index);
  index = -1;
  tab = lexer(strdup(*((*node)->action)), (char *[]) {"&&", "||", NULL},
	      "\"\"''", false);
  if (!tab)
    return (1);
  if (!tab[0])
    {
      werror(E_BAD_PIPE, NULL, false);
      return (1);
    }
  start = actual = NULL;
  while (tab[++index] && tab[index + 1])
    add_logical(&actual, &start, &tab[index], tab[index + tablen(tab) + 1]);
  insert_node(&actual, NULL, &tab[index], 1);
  if (!start)
    start = actual;
  *node = start;
  return (0);
}

int	parser_logic(t_node **node)
{
  if ((*node)->op)
    {
      if (parser_logic(&(*node)->left))
	return (1);
      return (parser_logic(&(*node)->right));
    }
  else
    return (upgrade_logical(node));
}
