/*
** my_list4.c for my_list in /home/onehandedpenguin/Dev/lib"my/list/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Mon Dec 19 13:38:53 2016 Paul Laffitte
** Last update Wed Dec 21 01:40:55 2016 Paul Laffitte
*/

#include "my/containers/my_list.h"
#include "my/utils/memory.h"

static t_list_elem	*divide_tab(t_list_elem *first, t_list_elem *last,
				    t_list_cmp comparator, t_order order)
{
  t_list_elem		*pivot;

  pivot = first;
  while (first != last)
    {
      if (comparator(first->data, last->data) == order)
	{
	  my_swap_ptr(&pivot->data, &first->data);
	  pivot = pivot->next;
	}
      first = first->next;
    }
  my_swap_ptr(&pivot->data, &first->data);
  return (pivot);
}

static void		quick_sort(t_list_elem *e1, t_list_elem *e2,
				   t_list_cmp comparator, t_order order)
{
  t_list_elem		*pivot;

  if (e2 != NULL && e1 != e2 && e1 != e2->next)
    {
      pivot = divide_tab(e1, e2, comparator, order);
      quick_sort(e1, pivot->prev, comparator, order);
      quick_sort(pivot->next, e2, comparator, order);
    }
}

void			sort_list(t_list *list, t_list_cmp comparator,
				  t_order order)
{
  t_type_list		original_type;

  original_type = list->type;
  if (list->type == CIRCULAR_LIST)
    set_list_type(list, LINKED_LIST);
  quick_sort(list->front, list->back, comparator, order);
  set_list_type(list, original_type);
}
