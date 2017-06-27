/*
** add_par.c for bonus in /home/arbona/CPool/CPool_bistro-matic/bonus/src/
**
** Made by Thomas Arbona
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Sun Nov  6 18:09:49 2016 Thomas Arbona
** Last update Sun Nov  6 20:23:29 2016 Arthur Chaloin
*/
#include "my.h"
#include "bistro-matic.h"
#include "bonus.h"

char	*add_par(char *expr)
{
  char	*result;

  if (!(result = malloc(sizeof(char) * (my_strlen(expr) + 3))))
    exit_error(MALLOC_FAILED);
  result[0] = g_arithmetic.ops[OP_PAR_O];
  my_strcpy(result + 1, expr);
  result[my_strlen(expr) + 1] = g_arithmetic.ops[OP_PAR_C];
  result[my_strlen(expr) + 2] = '\0';
  return (result);
}
