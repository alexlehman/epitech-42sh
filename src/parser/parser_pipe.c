/*
** parser_pipe.c for mysh in /home/arthur/B2/PSU/PSU_2016_minishell2/src/parser/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Wed Apr  5 19:43:26 2017 Arthur Chaloin
** Last update Sun May 21 22:05:20 2017 Arthur Chaloin
*/
#include <unistd.h>
#include <stdlib.h>
#include "command.h"
#include "parser.h"
#include "error.h"
#include "utils.h"

static void	epur_spaces(char **str)
{
  int		index;

  index = -1;
  while ((*str)[++index] && (*str)[index] == ' ');
  *str += index;
  while ((*str)[++index]);
  while ((*str)[--index] && (*str)[index] == ' ');
  (*str)[index + 1] = 0;
}

static void	add_pipe(t_node **actual, t_node **start, char **data)
{
  insert_node(actual, "|", NULL, 1);
  if (!*start)
    *start = *actual;
  else
    *actual = (*actual)->right;
  insert_node(actual, NULL, data, 0);
}

static int	upgrade_pipe(t_node **node)
{
  int		index;
  char		**t;
  t_node	*actual;
  t_node	*start;

  epur_spaces((*node)->action);
  index = -1;
  t = lexer(strdup(*((*node)->action)), (char *[]) {"|", NULL}, INHIB, false);
  if (!t)
    return (1);
  if (!t[0])
    {
      werror(E_BAD_PIPE, NULL, false);
      return (1);
    }
  if (check_syntax(*((*node)->action)) || check_doubles(*((*node)->action)))
    return (1);
  start = actual = NULL;
  while (t[++index] && t[index + 1])
    add_pipe(&actual, &start, &t[index]);
  insert_node(&actual, NULL, &t[index], 1);
  if (!start)
    start = actual;
  *node = start;
  return (0);
}

int	parser_pipes(t_node **node)
{
  if ((*node)->op)
    {
      if (parser_pipes(&(*node)->left))
	return (1);
      return (parser_pipes(&(*node)->right));
    }
  else
    return (upgrade_pipe(node));
}
