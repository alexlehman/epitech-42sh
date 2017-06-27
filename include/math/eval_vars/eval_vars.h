/*
** eval_vars.h for  in /home/arbona/CPool/CPool_bistro-matic/bonus/include/eval_vars/
**
** Made by Thomas Arbona
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Sun Nov  6 11:57:03 2016 Thomas Arbona
** Last update Sun Nov  6 20:17:10 2016 Arthur Chaloin
*/

#ifndef EVAL_VARS_H_
# define EVAL_VARS_H_

typedef struct	s_var
{
  char		*name;
  char		*value;
}		t_var;

char	*eval_vars(char *expr);
char	*replace_vars(char *expr, t_var **vars);
t_var	*get_var(t_var **vars, char *name);
t_var	*init_var(char *expr, t_var **vars, int *cursor);

#endif /* !EVAL_VARS_H_ */
