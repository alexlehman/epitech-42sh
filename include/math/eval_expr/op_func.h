/*
** tree_operations.h for eval_expr in /home/arthur/Documents/Piscine/CPool_evalexpr/include/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Tue Oct 25 17:56:54 2016 Arthur Chaloin
** Last update Fri Oct 28 15:53:20 2016 Thomas Arbona
*/

#ifndef OP_FUNC_H
# define OP_FUNC_H

typedef struct	s_op_func
{
  int		ope;
  char		*(*func_ptr)(char *, char *);
}		t_op_func;

extern t_op_func	ope_tab[];

#endif /* !OP_FUNC_H */
