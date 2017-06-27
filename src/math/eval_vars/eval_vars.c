/*
** eval_vars.c for  in /home/arbona/CPool/CPool_bistro-matic/bonus/include/eval_vars/
**
** Made by Thomas Arbona
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Sun Nov  6 11:49:04 2016 Thomas Arbona
** Last update Sun Nov  6 20:27:09 2016 Arthur Chaloin
*/
#include "my.h"
#include "bistro-matic.h"
#include "bonus.h"

void		replace_var(t_var **vars, char **expr, t_cursors *cursors)
{
  t_var		*var;

  if (!(var = get_var(vars, my_strndup(*expr + cursors->one + 1,
    cursors->two - cursors->one - 1))))
      exit_error(SYNTAX_ERR);
  *expr = my_str_replace(*expr, cursors->one, cursors->two - 1,
			 add_par(var->value));
  cursors->two = cursors->one;
  cursors->one = -1;
}

char		*replace_vars(char *expr, t_var **vars)
{
  t_cursors	cursors;

  cursors.one = -1;
  cursors.two = 0;
  while (expr[cursors.two] != '\0')
    {
      if (expr[cursors.two] == g_arithmetic.ops[OP_VAR])
	{
	  if (cursors.one != -1)
	    exit_error(SYNTAX_ERR);
	  cursors.one = cursors.two;
	}
      else if (my_strstr(g_arithmetic.ops, my_strndup(expr + cursors.two, 1))
	       && expr[cursors.two] != g_arithmetic.ops[OP_VAR]
	       && cursors.one != -1)
	replace_var(vars, &expr, &cursors);
      cursors.two += 1;
    }
  if (cursors.one != -1)
    replace_var(vars, &expr, &cursors);
  return (expr);
}

char		*eval_vars(char *expr)
{
  char		**piece;
  int		index;
  int		len;
  t_var		**vars;
  int		vars_index;

  index = -1;
  vars_index = 0;
  piece = split_root_sep(expr);
  len = my_tablen(piece);
  if (my_strcmp("", piece[len - 1]) == 0)
    exit_error(SYNTAX_ERR);
  if (len == 1)
    return (expr);
  if (!(vars = malloc(sizeof(t_var *) * (len))))
    exit_error(MALLOC_FAILED);
  vars[0] = NULL;
  while (++index < len - 1)
    init_var(piece[index], vars, &vars_index);
  expr = replace_vars(piece[len - 1], vars);
  if (my_str_contain(expr, g_arithmetic.ops[OP_EGAL]) >= 0)
    exit_error(SYNTAX_ERR);
  return (expr);
}
