/*
** gentree.c for eval_expr in /home/arthur/Documents/Piscine/CPool_evalexpr/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Wed Oct 26 09:07:41 2016 Arthur Chaloin
** Last update Sun May 21 18:51:05 2017 Arthur Chaloin
*/
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "bistro-matic.h"

t_op_func	ope_tab[] = {
  {OP_ADD, &my_add},
  {OP_SUB, &my_sub},
  {OP_MUL, &my_mul},
  {OP_DIV, &my_div},
  {OP_MOD, &my_mod},
  {0, NULL}
};

t_tree_node	*create_node(char *nb, char *(*func_op)(char *, char *))
{
  t_tree_node	*element;

  if (!(element = malloc(sizeof(t_tree_node))))
    exit_error(MALLOC_FAILED);
  element->nb = nb;
  element->func_op = func_op;
  element->left = NULL;
  element->right = NULL;
  return (element);
}

void	init_cursors(t_tree_cursors *cursors, char **split_expr)
{
  cursors->last_expr_high = 0;
  cursors->root = NULL;
  cursors->last_op = NULL;
  cursors->last_low = NULL;
  cursors->new_node = NULL;
  cursors->index = my_tablen(split_expr) - 2;
}

t_tree_node		*gentree(char *expr)
{
  char			**split_expr;
  t_tree_cursors	cursors;

  split_expr = lexer_math(expr);
  init_cursors(&cursors, split_expr);
  while (cursors.index > 0)
    {
      if (my_strstr(g_arithmetic.ope_low, split_expr[cursors.index]))
	{
	  insert_ope_node(split_expr[cursors.index][0], &cursors, 0);
	  cursors.index2 = cursors.last_expr_high;
	  while (cursors.index2 >= 1 &&
		 my_strstr(g_arithmetic.ope_high, split_expr[cursors.index2]))
	    cursors.index2 = insert_priority_nodes(&cursors, split_expr,
	      (cursors.index2 == cursors.last_expr_high));
	  cursors.last_op = cursors.last_low;
	  insert_last_nodes(cursors, split_expr, cursors.index);
	  cursors.last_expr_high = 0;
	}
      else if (my_strstr(g_arithmetic.ope_high, split_expr[cursors.index])
	       && !cursors.last_expr_high)
	cursors.last_expr_high = cursors.index;
      cursors.index -= 2;
    }
  return (cursors.root);
}
