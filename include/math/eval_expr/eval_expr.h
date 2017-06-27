/*
** eval_expr.h for eval_expr in /home/arthur/Documents/Piscine/CPool_evalexpr/include/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Wed Oct 26 14:45:34 2016 Arthur Chaloin
** Last update Sun May 21 18:51:37 2017 Arthur Chaloin
*/

#ifndef EVAL_EXPR_H_
# define EVAL_EXPR_H_

# include "bistro-matic.h"
# include "op_func.h"
# include "tree_node.h"
# include "gentree.h"
# include "eval_expr/lexer/lexer.h"

t_tree_node	*eval_expr(char *str);
int		insert_ope_node(char ope, t_tree_cursors *cursors, int side);
int		insert_nb_node(char *str_nb,
			       t_tree_cursors *cursors,
			       int side);
void		insert_last_nodes(t_tree_cursors cursors,
				  char **split_expr,
				  int index);
int	insert_priority_nodes(t_tree_cursors *cursors,
			      char **split_expr, int side);

char	*my_add(char *a, char *b);
char	*my_sub(char *a, char *b);
char	*my_mul(char *a, char *b);
char	*my_div(char *a, char *b);
char	*my_mod(char *a, char *b);

char	**lexer_math(char *str);

void	init_cursors(t_tree_cursors *cursors, char **split_expr);

char	*calculate_tree(t_tree_node *root);

t_tree_node	*gentree(char *expr);
t_tree_node	*create_node(char *nb, char *(*func_op)(char *, char *));

#endif /* !EVAL_EXPR_H_ */
