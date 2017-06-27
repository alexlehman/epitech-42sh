/*
** lexer.c for eval_expr in /home/arthur/Documents/Piscine/CPool_evalexpr/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Wed Oct 26 14:44:22 2016 Arthur Chaloin
** Last update Sun May 21 18:51:09 2017 Arthur Chaloin
*/
#include <stdlib.h>
#include "my.h"
#include "bistro-matic.h"

static char	**array_push(t_array_cursor *arr, char *str)
{
  arr->cursor += 1;
  arr->array[arr->cursor] = str;
  return (arr->array);
}

static int	count_element(char *str,
			      int count,
			      int level,
			      t_cursors *cursors)
{
  update_level(&level, str[cursors->two]);
  if (str[cursors->two] == '\0')
    return (count + 1);
  if ((my_strstr(g_arithmetic.ope_low, my_strndup(str + cursors->two, 1)) ||
      my_strstr(g_arithmetic.ope_high, my_strndup(str + cursors->two, 1))) &&
      level == 0)
    {
      if (cursors->two != cursors->one)
	count += 1;
      cursors->two += 1;
      cursors->one = cursors->two;
      return (count_element(str, count + 1, level, cursors));
    }
  cursors->two += 1;
  return (count_element(str, count, level, cursors));
}

t_array_cursor	*lexer_end(char *str,
			   t_array_cursor *arr,
			   t_cursors *cursors)
{
  if (cursors->one == cursors->two)
    cursors->two += 1;
  array_push(arr, my_strndup(str + cursors->one, cursors->two - cursors->one));
  return (arr);
}

static t_array_cursor	*lexer_rec(char *str,
				   t_array_cursor *arr,
				   int level,
				   t_cursors *cursors)
{
  update_level(&level, str[cursors->two]);
  if (str[cursors->two] == '\0')
    return (lexer_end(str, arr, cursors));
  if ((my_strstr(g_arithmetic.ope_low, my_strndup(str + cursors->two, 1)) ||
      my_strstr(g_arithmetic.ope_high, my_strndup(str + cursors->two, 1))) &&
      level == 0)
    {
      if (cursors->one != cursors->two)
	array_push(arr, my_strndup(str + cursors->one,
				   cursors->two - cursors->one));
      cursors->one = cursors->two;
      if (!(my_strstr(g_arithmetic.ope_low, my_strndup(str + cursors->two, 1))
	    && cursors->two == 0) &&
	  !(my_strstr(g_arithmetic.ope_low, my_strndup(str + cursors->two, 1))
	    && my_strstr(g_arithmetic.ope_high,
		      my_strndup(str + cursors->two - 1, 1))))
	{
	  array_push(arr, my_strndup(str + cursors->one, 1));
	  cursors->one += 1;
	}
    }
  cursors->two += 1;
  return (lexer_rec(str, arr, level, cursors));
}

char			**lexer_math(char *str)
{
  t_array_cursor	arr;
  int			count;
  t_cursors		cursors;

  normalize_sign(&str);
  reset_lexer_cursors(&cursors);
  handle_block(&str);
  count = (!is_sign_block(str))
    ? count_element(str, 0, 0, &cursors) : 3;
  if (!(arr.array = malloc(sizeof(char *) * (count + 3))))
    exit_error(MALLOC_FAILED);
  arr.cursor = -1;
  array_push(&arr, my_strndup(g_arithmetic.base, 1));
  array_push(&arr, my_strndup(g_arithmetic.ops + OP_ADD, 1));
  reset_lexer_cursors(&cursors);
  if (is_sign_block(str))
    {
      array_push(&arr, my_strndup(g_arithmetic.base, 1));
      array_push(&arr, my_strndup(str, 1));
      array_push(&arr, my_strndup(str + 1, my_strlen(str) - 1));
    }
  else
    lexer_rec(str, &arr, 0, &cursors);
  return (array_push(&arr, NULL));
}
