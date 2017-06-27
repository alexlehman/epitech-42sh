/*
** node.c for mysh.h in /home/arthur/Documents/B1-Systeme_UNIX/PSU_2016_minishell1/src/parser/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Wed Jan  4 17:06:02 2017 Arthur Chaloin
** Last update Fri Apr 28 21:22:50 2017 Arthur Chaloin
*/
#include <stdlib.h>
#include "command.h"
#include "error.h"
#include "my.h"

void		insert_node(t_node **parent, char *op, char **action, int side)
{
  t_node	*new;

  new = galloc(sizeof(t_node));
  new->op = op;
  new->action = action;
  new->right = NULL;
  new->left = NULL;
  if (*parent)
    {
      if (side)
	(*parent)->right = new;
      else
	(*parent)->left = new;
    }
  else
    *parent = new;
}
