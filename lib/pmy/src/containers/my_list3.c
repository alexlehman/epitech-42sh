/*
** my_list3.c for my_list in /home/onehandedpenguin/Dev/mylib/list/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Thu Nov 24 08:58:59 2016 Paul Laffitte
** Last update Thu Dec 22 02:09:10 2016 Paul Laffitte
*/

#include <stdlib.h>
#include "my/containers/my_list.h"
#include "my/utils/errors.h"

void		set_list_type(t_list *list, t_type_list type)
{
  list->type = type;
  if (type == CIRCULAR_LIST)
    {
      list->front->prev = list->back;
      list->back->next = list->front;
    }
  else if (type == LINKED_LIST)
    {
      list->front->prev = NULL;
      list->back->next = NULL;
    }
}

int		turn_list_left(t_list *list)
{
  if (list->type == CIRCULAR_LIST)
    {
      list->front = list->front->prev;
      list->back = list->back->prev;
    }
  return (0);
}

int		turn_list_right(t_list *list)
{
  if (list->type == CIRCULAR_LIST)
    {
      list->front = list->front->next;
      list->back = list->back->next;
    }
  return (0);
}

static int	elem_to_tab(t_list *list, t_list_elem *elem, t_tabber *tabber)
{
  (void)list;
  tabber->tab[tabber->index] = elem->data;
  tabber->index += 1;
  return (0);
}

void		**list_to_tab(t_list *list)
{
  t_tabber	tabber;

  if (list == NULL
      || !(tabber.tab = malloc(sizeof(void*) * (list->size + 1))))
    return (ERROR_NULL);
  tabber.index = 0;
  if (exec_list(list, (t_list_func)&elem_to_tab, &tabber) == ERROR_84)
    {
      free(tabber.tab);
      return (ERROR_NULL);
    }
  tabber.tab[list->size] = NULL;
  return (tabber.tab);
}
