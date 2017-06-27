/*
** tree_node.h for eval_expr in /home/arthur/Documents/Piscine/CPool_evalexpr/include/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Tue Oct 25 16:01:47 2016 Arthur Chaloin
** Last update Fri Oct 28 16:01:36 2016 Thomas Arbona
*/

#ifndef TREE_NODE_H_
# define TREE_NODE_H_

typedef struct		s_tree_node
{
  char			*nb;
  char			*(*func_op)(char *, char *);
  struct s_tree_node	*left;
  struct s_tree_node	*right;
}			t_tree_node;

#endif /* !TREE_NODE_H_ */
