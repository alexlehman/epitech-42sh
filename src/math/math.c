/*
** main.c for bistro-matic in /home/arthur/Documents/Piscine/Projets/CPool_bistro-matic/src/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Thu Oct 27 15:38:08 2016 Arthur Chaloin
** Last update Sun May 21 21:22:00 2017 Arthur Chaloin
*/
#include "my.h"
#include "bistro-matic.h"
#include "bonus.h"

t_arithmetic	g_arithmetic;

t_calc_func	g_calc_func[] = {
  {"pow", 2, &infin_pow},
  {"sqrt", 1, &infin_sqrt},
  {"fact", 1, &infin_fact},
  {"opposite", 1, &infin_opposite},
  {"abs", 1, &infin_abs},
  {"transpos", 3, &transposition},
  {"answer", 0, &answer},
  {NULL, 0, NULL}
};

int	display_help()
{
  my_putstr("USAGE\n\t./calc base operators size_read\n\n");
  my_putstr("DESCRIPTION\n\tbase\t\tall the symbols of the base\n\t");
  my_putstr("operators\tthe symbols for the parenthesis and the 9 operators");
  my_putstr("\n\tsize_read\tnumber of characters to be read");
  return (0);
}

void	init_g_arithmetic()
{
  g_arithmetic.base = strdup("0123456789");
  g_arithmetic.len_base = my_strlen(g_arithmetic.base);
  g_arithmetic.ops = strdup("()+-*/%#,@=");
  g_arithmetic.ope_low[0] = g_arithmetic.ops[OP_ADD];
  g_arithmetic.ope_low[1] = g_arithmetic.ops[OP_SUB];
  g_arithmetic.ope_low[2] = '\0';
  g_arithmetic.ope_high[0] = g_arithmetic.ops[OP_MUL];
  g_arithmetic.ope_high[1] = g_arithmetic.ops[OP_DIV];
  g_arithmetic.ope_high[2] = g_arithmetic.ops[OP_MOD];
  g_arithmetic.ope_high[3] = '\0';
}

char		*handle_expr(char *expr)
{
  t_tree_node	*tree;
  char		*result;

  check_func(expr);
  expr = eval_func(expr);
  if (check_expr(expr))
    return (NULL);
  tree = eval_expr(expr);
  if (!(result = calculate_tree(tree)))
    exit_error(DIV_BY_ZERO);
  return (result);
}

char		*eval(char *expr)
{
  char		*result;

  init_g_arithmetic();
  expr = eval_vars(expr);
  result = handle_expr(expr);
  return (result);
}
