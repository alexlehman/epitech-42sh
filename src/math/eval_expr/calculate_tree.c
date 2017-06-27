/*
** calculate.c for eval_expr in /home/arbona/CPool/CPool_evalexpr
**
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
**
** Started on  Wed Oct 26 15:57:43 2016 Thomas Arbona
** Last update Fri Nov  4 11:18:57 2016 Arthur Chaloin
*/
#include "my.h"
#include "eval_expr/eval_expr.h"

char	*calculate_tree(t_tree_node *root)
{
  char	*nb1;
  char	*nb2;

  nb1 = root->left->func_op
    ? calculate_tree(root->left)
    : root->left->nb;
  nb2 = root->right->func_op
    ? calculate_tree(root->right)
    : root->right->nb;
  return ((nb1 == NULL || nb2 == NULL) ? NULL : root->func_op(nb1, nb2));
}
