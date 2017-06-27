/*
** nodes_insert.c for eval_expr in /home/arthur/Documents/Piscine/CPool_evalexpr/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Wed Oct 26 16:06:11 2016 Arthur Chaloin
** Last update Fri Nov  4 11:24:38 2016 Arthur Chaloin
*/
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "eval_expr/eval_expr.h"

int		insert_nb_node(char *nb, t_tree_cursors *cursors, int side)
{
  t_tree_node	*node;

  if (nb[0] == g_arithmetic.ops[OP_SUB] ||
      nb[0] == g_arithmetic.ops[OP_PAR_O])
    node = gentree(nb);
  else
    node = create_node(nb, NULL);
  if (side)
    cursors->last_op->right = node;
  else
    cursors->last_op->left = node;
  return (0);
}

int		insert_ope_node(char ope, t_tree_cursors *cursors, int side)
{
  int		index;
  t_tree_node	*node;

  index = 0;
  while (g_arithmetic.ops[index] && g_arithmetic.ops[index] != ope)
    index += 1;
  if (!ope_tab[index - 2].func_ptr)
    return (EXIT_ERROR);
  node = create_node(NULL, ope_tab[index - 2].func_ptr);
  if (!cursors->root)
    cursors->root = node;
  else if (side)
    cursors->last_op->right = node;
  else
    cursors->last_op->left = node;
  if (my_strstr(g_arithmetic.ope_low, my_strndup(g_arithmetic.ops + index, 1)))
    cursors->last_low = node;
  cursors->last_op = node;
  return (0);
}

int	insert_priority_nodes(t_tree_cursors *cursors,
			      char **split_expr,
			      int side)
{
  insert_ope_node(split_expr[cursors->index2][0], cursors, side);
  insert_nb_node(split_expr[cursors->index2 + 1], cursors, 1);
  if (cursors->index2 - 2 < 0 ||
      my_strstr(g_arithmetic.ope_low,
		my_strndup(split_expr[cursors->index2 - 2], 1)))
      insert_nb_node(split_expr[cursors->index2 - 1], cursors, 0);
  return (cursors->index2 - 2);
}

void	insert_last_nodes(t_tree_cursors cursors, char **split_expr, int index)
{
  if (!cursors.last_expr_high)
    insert_nb_node(split_expr[index + 1], &cursors, 1);
  if (index == 1)
    insert_nb_node(split_expr[index - 1], &cursors, 0);
}
