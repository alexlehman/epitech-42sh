/*
** my_list5.c for libmy in /home/onehandedpenguin/Dev/libmy/src/containers/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Wed Dec 28 17:30:38 2016 Paul Laffitte
** Last update Wed Dec 28 17:33:11 2016 Paul Laffitte
*/

#include "my/containers/my_list.h"

void	clear_list(t_list *list)
{
  int	size;
  int	i;

  size = list->size;
  i = 0;
  while (i < size)
    {
      pop(list, list->front);
      i += 1;
    }
}
