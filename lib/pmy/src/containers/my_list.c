/*
** list.c for eval_expr in /home/onehandedpenguin/CPool_evalexpr/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Tue Oct 25 17:42:53 2016 Paul Laffitte
** Last update Fri Apr 28 21:07:19 2017 Arthur Chaloin
*/

#include <stdlib.h>
#include <stdio.h>
#include "my/containers/my_list.h"
#include "my/utils/errors.h"

t_list		*create_list(t_type_list type)
{
  t_list	*list;

  if (!(list = malloc(sizeof(t_list))))
    return (ERROR_NULL);
  list->front = NULL;
  list->back = NULL;
  list->size = 0;
  list->type = type;
  return (list);
}

int		exec_list(t_list *list, t_list_func func, void *data)
{
  t_list_elem	*iterator;
  int		i;

  iterator = list->front;
  i = 0;
  while (i < list->size)
    {
      if (func(list, iterator, data) == ERROR_84)
	return (ERROR_84);
      iterator = iterator->next;
      i += 1;
    }
  return (0);
}

t_list		*rev_list(t_list *list)
{
  t_list_elem	*iterator;
  t_list_elem	*tmp;
  int		i;

  iterator = list->front;
  i = 0;
  while (i < list->size)
    {
      tmp = iterator->next;
      iterator->next = iterator->prev;
      iterator->prev = tmp;
      iterator = tmp;
      i += 1;
    }
  tmp = list->front;
  list->front = list->back;
  list->back = tmp;
  return (list);
}

int		free_list(t_list *list)
{
  while (list->size != 0)
    {
      if (pop(list, list->front) == ERROR_84)
	return (ERROR_84);
    }
  free(list);
  return (0);
}
