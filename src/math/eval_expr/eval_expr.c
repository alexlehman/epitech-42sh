/*
** main.c for eval_expr in /home/arthur/Documents/Piscine/CPool_evalexpr/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Tue Oct 25 19:13:48 2016 Arthur Chaloin
** Last update Fri Nov  4 12:09:17 2016 Arthur Chaloin
*/
#include "my.h"
#include "eval_expr/eval_expr.h"

t_tree_node	*eval_expr(char *str)
{
  t_tree_node	*tree;

  tree = gentree(str);
  return (tree);
}
