/*
** parser_redir.c for mysh in /home/arthur/B2/PSU/PSU_2016_minishell2/src/parser/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Wed Apr  5 19:43:51 2017 Arthur Chaloin
** Last update Sun May 21 22:05:58 2017 Arthur Chaloin
*/
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "command.h"
#include "parser.h"
#include "error.h"
#include "utils.h"

static int	gen_redir_tree(t_node **node, t_redir *redir)
{
  t_node	*new;

  new = NULL;
  if (redir->left)
    insert_node(&new, (redir->ltype == 1) ? "<" : "<<", NULL, 1);
  if (redir->left && !redir->right)
    insert_node(&new, NULL, strsplit(redir->left, " "), 1);
  else if (redir->right && redir->left)
    {
      insert_node(&new, (redir->rtype == 1) ? ">" : ">>", NULL, 1);
      insert_node(&(new->right), NULL, strsplit(redir->left, " "), 0);
      insert_node(&(new->right), NULL, strsplit(redir->right, " "), 1);
    }
  else if (redir->right && !redir->left)
    {
      insert_node(&new, (redir->rtype == 1) ? ">" : ">>", NULL, 1);
      insert_node(&new, NULL, strsplit(redir->right, " "), 1);
    }
  insert_node(&new, NULL, redir->command, 0);
  *node = new;
  return (0);
}

static void	add_redir(t_redir *redir, char *str, int side)
{
  int		index;

  if (side)
    {
      index = -1;
      if (str[0] == '>' && str[1] == '>')
	redir->rtype = 2;
      else
	redir->rtype = 1;
      str += redir->rtype;
      while (str[++index] && str[index] != '<' && str[index] != '>');
      redir->right = strndup(str, index);
    }
  else
    {
      index = -1;
      if (str[0] == '<' && str[1] == '<')
	redir->ltype = 2;
      else
	redir->ltype = 1;
      str += redir->ltype;
      while (str[++index] && str[index] != '<' && str[index] != '>');
      redir->left = strndup(str, index);
    }
}

static int	get_command(t_node *node, t_redir *redir)
{
  int		index;

  if (redir->left && (index = -1))
    {
      while ((*(node->action))[++index] && (*(node->action))[index] != '<');
      while ((*(node->action))[++index] && (((*(node->action))[index] == 32) ||
	     (*(node->action))[index] == '<'))
	(*(node->action))[index] = '<';
      index--;
      while ((*(node->action))[++index] && (*(node->action))[index] != ' ')
	(*(node->action))[index] = '<';
    }
  if (redir->right && (index = -1))
    {
      while ((*(node->action))[++index] && (*(node->action))[index] != '>');
      while ((*(node->action))[++index] && (((*(node->action))[index] == 32) ||
	     (*(node->action))[index] == '>'))
	(*(node->action))[index] = '>';
      index--;
      while ((*(node->action))[++index] && (*(node->action))[index] != ' ')
	(*(node->action))[index] = '>';
    }
  redir->command = lexer(strdup(*(node->action)), (char *[]) {
			 " ", "\t", "<", ">", NULL}, "\"\"''", true);
  return ((!redir->command || !redir->command[0]));
}

static int	upgrade_node(t_node **node)
{
  int		index;
  t_redir	redir;

  redir.left = NULL;
  redir.right = NULL;
  index = -1;
  while ((*((*node)->action))[++index])
    {
      if ((*((*node)->action))[index] == '<')
	{
	  add_redir(&redir, (*((*node)->action)) + index, 0);
	  index += redir.ltype;
	}
      else if ((*((*node)->action))[index] == '>')
	{
	  add_redir(&redir, (*((*node)->action)) + index, 1);
	  index += redir.rtype;
	}
    }
  if (get_command(*node, &redir))
    {
      werror(E_BAD_PIPE, NULL, false);
      return (1);
    }
  return (gen_redir_tree(node, &redir));
}

int	parser_redirects(t_node **node)
{
  if ((*node)->op)
    {
      if (parser_redirects(&(*node)->left))
	return (1);
      return (parser_redirects(&(*node)->right));
    }
  else
    return (upgrade_node(node));
}
