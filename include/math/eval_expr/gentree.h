/*
** gentree.h for eval_expr in /home/arthur/Documents/Piscine/CPool_evalexpr/include/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Wed Oct 26 09:09:28 2016 Arthur Chaloin
** Last update Wed Oct 26 16:02:22 2016 Arthur Chaloin
*/

#ifndef GENTREE_H_
# define GENTREE_H_

typedef struct	s_tree_cursors
{
  int		last_expr_high;
  int		index;
  int		index2;
  t_tree_node	*root;
  t_tree_node	*last_op;
  t_tree_node	*last_low;
  t_tree_node	*new_node;
}		t_tree_cursors;

#endif /* !GENTREE_H_ */
