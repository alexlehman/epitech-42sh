/*
** operations.c for eval_expr in /home/arthur/Documents/Piscine/CPool_evalexpr/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Wed Oct 26 11:09:23 2016 Arthur Chaloin
** Last update Fri Nov  4 12:18:53 2016 Arthur Chaloin
*/
#include "my.h"
#include "bistro-matic.h"

char	*my_add(char *a, char *b)
{
  return (infin_add(a, b));
}

char	*my_sub(char *a, char *b)
{
  char	*sign_b;
  int	index;

  if (b[0] == g_arithmetic.ops[OP_SUB])
    return (my_add(a, b + 1));
  if (!(sign_b = malloc(sizeof(char) * (my_strlen(b) + 2))))
    exit_error(MALLOC_FAILED);
  index = 0;
  sign_b[0] = g_arithmetic.ops[OP_SUB];
  while (b[index] != '\0')
    {
      sign_b[index + 1] = b[index];
      index += 1;
    }
  sign_b[index + 1] = '\0';
  return (infin_add(a, sign_b));
}

char	*my_mul(char *a, char *b)
{
  return (karatsuba(a, b));
}

char	*my_div(char *a, char *b)
{
  if (is_zero(b))
    exit_error(DIV_BY_ZERO);
  return ((infin_div(a, b))->quotient);
}

char	*my_mod(char *a, char *b)
{
  if (is_zero(b))
    exit_error(DIV_BY_ZERO);
  return ((infin_div(a, b))->rest);
}
