/*
** my_list2.c for my_list in /home/onehandedpenguin/Dev/mylib/list/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Wed Nov 23 13:09:15 2016 Paul Laffitte
** Last update Fri Apr 28 20:37:11 2017 Arthur Chaloin
*/

#include <stdlib.h>
#include "my/containers/my_list.h"
#include "my/utils/errors.h"

int		push_back(t_list *list, void *data)
{
  t_list_elem	*list_elem;

  if (!(list_elem = malloc(sizeof(t_list_elem))))
    return (ERROR_84);
  list_elem->data = data;
  list_elem->prev = list->back;
  if (list->type == CIRCULAR_LIST)
    {
      list_elem->next = list->front;
      if (list->size != 0)
	list->front->prev = list_elem;
    }
  else
    list_elem->next = NULL;
  if (list->back != NULL)
    list->back->next = list_elem;
  list->back = list_elem;
  if (list->size == 0)
    list->front = list_elem;
  list->size += 1;
  return (0);
}

int		push_front(t_list *list, void *data)
{
  t_list_elem	*list_elem;

  if (!(list_elem = malloc(sizeof(t_list_elem))))
    return (ERROR_84);
  list_elem->data = data;
  list_elem->next = list->front;
  if (list->type == CIRCULAR_LIST)
    {
      list_elem->prev = list->back;
      if (list->size != 0)
	list->back->next = list_elem;
    }
  else
    list_elem->prev = NULL;
  if (list->front != NULL)
    list->front->prev = list_elem;
  list->front = list_elem;
  if (list->size == 0)
    list->back = list_elem;
  list->size += 1;
  return (0);
}

int		pop(t_list *list, t_list_elem *list_elem)
{
  if (list_elem == list->front)
    list->front = list_elem->next;
  if (list_elem == list->back)
    list->back = list_elem->prev;
  if (list_elem->prev != NULL)
    list_elem->prev->next = list_elem->next;
  if (list_elem->next != NULL)
    list_elem->next->prev = list_elem->prev;
  free(list_elem);
  list->size -= 1;
  return (0);
}

t_list		*find(t_list *list, t_list_func finder_func,
			      t_list_finder *finder)
{
  finder->found = create_list(LINKED_LIST);
  if (exec_list(list, finder_func, finder) == ERROR_84)
    return (ERROR_NULL);
  return (finder->found);
}
