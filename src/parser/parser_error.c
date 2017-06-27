/*
** parser_error.c for mysh in /home/arthur/B2/PSU/PSU_2016_minishell2/src/parser/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Wed Apr  5 19:45:14 2017 Arthur Chaloin
** Last update Fri Apr 28 21:20:28 2017 Arthur Chaloin
*/
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "command.h"
#include "parser.h"
#include "error.h"

int	check_ambigues(t_node **node)
{
  if ((*node)->op)
    {
      if (!strcmp((*node)->op, ";"))
	{
	  if (check_ambigues(&(*node)->left))
	    return (1);
	  return (check_ambigues(&(*node)->right));
	}
      else if (!strcmp((*node)->op, "|"))
	{
	  if (((*node)->left->op && (*node)->left->op[0] == '>') ||
	      ((*node)->left->op && (*node)->left->op[0] == '<' &&
	       (*node)->left->right->op && (*node)->left->right->op[0] == '>'))
	    return (2);
	  if (((*node)->right->op && (*node)->right->op[0] == '<'))
	    return (1);
	}
    }
  return (0);
}

int		check_doubles(char *command)
{
  int		index;
  int		set[2];

  index = -1;
  set[0] = set[1] = 0;
  while (command[++index])
    {
      if (command[index] == '<')
	{
	  if (command[index + 1] == '<')
	    index++;
	  set[0]++;
	}
      if (command[index] == '>')
  	{
  	  if (command[index + 1] == '>')
  	    index++;
  	  set[1]++;
  	}
    }
  if (!(set[0] < 2 && set[1] < 2))
    werror((set[0] >= 2) ? E_AMBIGU_IN : E_AMBIGU_OUT, NULL, false);
  return (!(set[0] < 2 && set[1] < 2));
}

static int	syntax_handle_sep(int *sep, char *command, int *index)
{
  if (*sep)
    {
      if (*sep == 42 && command[*index] == '|')
	{
	  werror(E_BAD_PIPE, NULL, false);
	  return (1);
	}
      else if (*sep == '<' || *sep == '>' ||
	       (*sep == '|' && command[*index] != '>'))
	{
	  werror((*sep == '|' || (*sep == 42 && command[*index] == '|')) ?
		 E_BAD_PIPE : E_BAD_REDIR, NULL, false);
	  return (1);
	}
    }
  *sep = command[*index];
  if (command[*index + 1] == '>' || command[*index + 1] == '<')
    (*index)++;
  return (0);
}

int	check_syntax(char *command)
{
  int		index;
  int		sep;

  index = -1;
  sep = 42;
  while (command[++index])
    {
      if (command[index] == '|' || command[index] == '<' ||
	  command[index] == '>')
	{
	  if (syntax_handle_sep(&sep, command, &index))
	    return (1);
	}
      else if (command[index] != ' ' && command[index] != '\t')
	sep = 0;
    }
  if (sep)
    {
      werror((sep == '|') ? E_BAD_PIPE : E_BAD_REDIR, NULL, false);
      return (1);
    }
  return (0);
}
