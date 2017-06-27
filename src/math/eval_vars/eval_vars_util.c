/*
** eval_vars_util.c for bistro-matic in /home/arthur/Documents/Piscine/Projects/CPool_bistro-matic/bonus/src/eval_vars/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Sun Nov  6 20:14:47 2016 Arthur Chaloin
** Last update Sun Nov  6 20:16:46 2016 Arthur Chaloin
*/
#include "my.h"
#include "bistro-matic.h"
#include "bonus.h"

t_var		*get_var(t_var **vars, char *name)
{
  int		index;

  index = 0;
  while (vars[index] != NULL)
    {
      if (my_strcmp(vars[index]->name, name) == 0)
	return (vars[index]);
      index += 1;
    }
  return (NULL);
}

void	push_var(t_var **vars, int *cursor, t_var *var)
{
  vars[*cursor] = var;
  vars[*cursor + 1] = NULL;
  *cursor += 1;
}

t_var		*init_var(char *expr, t_var **vars, int *cursor)
{
  int		index;
  t_var		*var;
  t_var		*prev_var;

  index = 0;
  if (!(var = malloc(sizeof(t_var))))
    exit_error(MALLOC_FAILED);
  while (expr[index] != g_arithmetic.ops[OP_EGAL] &&
	 expr[index] != '\0')
    index += 1;
  if (expr[index] != g_arithmetic.ops[OP_EGAL] ||
      my_str_contain(expr + index + 1, g_arithmetic.ops[OP_EGAL]) >= 0)
    exit_error(SYNTAX_ERR);
  var->name = my_strndup(expr, index);
  var->value = my_strndup(expr + index + 1, my_strlen(expr) - index);
  if (var->name[0] == '\0' ||
      var->value[0] == '\0')
    exit_error(SYNTAX_ERR);
  var->value = replace_vars(var->value, vars);
  var->value = handle_expr(var->value);
  if ((prev_var = get_var(vars, var->name)))
    prev_var->value = var->value;
  else
    push_var(vars, cursor, var);
  return (var);
}
