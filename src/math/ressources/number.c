/*
** ressources.c for bistro-matic in /home/arthur/Documents/Piscine/Projects/CPool_bistro-matic/src/ressources/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Wed Nov  2 21:00:29 2016 John Doe
** Last update Fri Nov  4 11:55:06 2016 Arthur Chaloin
*/
#include "my.h"
#include "bistro-matic.h"

int	is_zero(char *nb)
{
  int	index;

  index = 0;
  while (nb[index])
    {
      if (nb[index] != g_arithmetic.base[0])
	return (0);
      index += 1;
    }
  return (1);
}

void	normalize(char **n1, char **n2)
{
  char  *tmp;
  char  **target;
  int   target_len;
  int   length;
  int   iterator;

  length = (my_strlen(*n1) > my_strlen(*n2)) ? my_strlen(*n1) : my_strlen(*n2);
  if ((my_strlen(*n1) == my_strlen(*n2)))
    return;
  if (!(tmp = malloc(sizeof(char) * (length + 1))))
    exit_error(MALLOC_FAILED);
  target = (my_strlen(*n1) > my_strlen(*n2)) ? n2 : n1;
  target_len = my_strlen(*target);
  iterator = 0;
  while (iterator < length)
    {
      tmp[iterator] = (length - iterator <= target_len)
	? (*target)[iterator - (length - target_len)] : g_arithmetic.base[0];
      if (tmp[iterator] == g_arithmetic.ops[OP_SUB])
	my_swapchar(&tmp, 0, iterator);
      iterator += 1;
    }
  tmp[iterator] = '\0';
  *target = tmp;
}

int	max_abs(char *nb1, char *nb2)
{
  int	cursor;

  cursor = 1;
  if (nb1[0] == g_arithmetic.ops[OP_SUB] && nb2[0] != g_arithmetic.base[0])
    return (0);
  if (nb2[0] == g_arithmetic.ops[OP_SUB] && nb1[0] != g_arithmetic.base[0])
    return (1);
  while (nb1[cursor] != '\0')
    {
      if (nb2[cursor] != nb1[cursor])
	return (!(my_str_contain(g_arithmetic.base, nb2[cursor])
		  > my_str_contain(g_arithmetic.base, nb1[cursor])));
      cursor += 1;
    }
  return (1);
}

int	max_nb(char *nb1, char *nb2)
{
  int	cursor;
  char	*tmp_nb1;
  char	*tmp_nb2;

  tmp_nb1 = my_strdup(nb1);
  tmp_nb2 = my_strdup(nb2);
  normalize(&tmp_nb1, &tmp_nb2);
  cursor = 1;
  if (tmp_nb1[0] == g_arithmetic.ops[OP_SUB] &&
      tmp_nb2[0] != g_arithmetic.ops[OP_SUB])
    return (0);
  if (tmp_nb2[0] == g_arithmetic.ops[OP_SUB] &&
      tmp_nb1[0] != g_arithmetic.ops[OP_SUB])
    return (1);
  if (tmp_nb2[0] != tmp_nb1[0])
    return (!(my_str_contain(g_arithmetic.base, tmp_nb2[0])
	      > my_str_contain(g_arithmetic.base, tmp_nb1[0])));
  while (tmp_nb1[cursor] != '\0')
  {
    if (tmp_nb2[cursor] != tmp_nb1[cursor])
      return (!(my_str_contain(g_arithmetic.base, tmp_nb2[cursor])
		> my_str_contain(g_arithmetic.base, tmp_nb1[cursor])));
    cursor += 1;
  }
  return (1);
}
