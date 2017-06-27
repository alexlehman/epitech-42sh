/*
** karatsuba_util.c for karatsuba in /home/arbona/CPool/CPool_bistro-matic/src/karatsuba/
**
** Made by Thomas Arbona
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Nov  1 15:56:41 2016 Thomas Arbona
** Last update Fri Nov  4 11:54:57 2016 Arthur Chaloin
*/
#include "my.h"
#include "bistro-matic.h"

char	*shift_nb(char *nb, int pow)
{
  int	index;
  int	size;
  char	*new_nb;

  size = my_strlen(nb);
  index = size;
  if (!(new_nb = malloc(sizeof(char) * (size + pow + 1))))
    exit_error(MALLOC_FAILED);
  my_strcpy(new_nb, nb);
  while (index < size + pow)
    {
      new_nb[index] = g_arithmetic.base[0];
      index += 1;
    }
  new_nb[size + pow] = '\0';
  return (new_nb);
}

char	*split(char *str, int pos, char **dest1, char **dest2)
{
  if (pos >= my_strlen(str))
    {
      *dest2 = str;
      *dest1 = my_strndup(g_arithmetic.base, 1);
      return (str);
    }
  if (!((*dest1 = malloc(sizeof(char) * (my_strlen(str) - pos))) ||
	(*dest2 = malloc(sizeof(char) * pos))))
    exit_error(MALLOC_FAILED);
  *dest2 = my_strdup(str + my_strlen(str) - pos);
  *dest1 = my_strndup(str, my_strlen(str) - pos);
  return (str);
}

int	krtsb_del_sign(char **x, int isneg)
{
  if ((*x)[0] == g_arithmetic.ops[OP_SUB])
    {
      isneg = (!isneg);
      (*x) += 1;
    }
  return (isneg);
}
