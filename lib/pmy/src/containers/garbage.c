/*
** garbage.c for libmy in /home/onehandedpenguin/Dev/libmy/src/containers/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Wed Jan  4 01:42:21 2017 Paul Laffitte
** Last update Fri Apr 28 20:50:50 2017 Arthur Chaloin
*/

#include "my/utils/errors.h"
#include "my/containers/my_list.h"
#include "my/containers/garbage.h"

t_gc			g_gc;

int			init_gc(int sub_collectors)
{
  int			i;

  g_gc.sub_collectors = sub_collectors;
  if ((g_gc.mallocated = malloc(sizeof(t_list*)
				* sub_collectors)) == ERROR_NULL
      || (g_gc.created = malloc(sizeof(t_list*)
				* sub_collectors)) == ERROR_NULL)
    return (ERROR_84);
  i = 0;
  while (i < sub_collectors)
    {
      if ((g_gc.mallocated[i] = create_list(LINKED_LIST)) == ERROR_NULL
	  || (g_gc.created[i] = create_list(LINKED_LIST)) == ERROR_NULL)
	return (ERROR_84);
      i++;
    }
  return (0);
}

void			gfree(int id_collector)
{
  t_list_elem		*iterator;
  t_list_elem		*tmp;

  if (id_collector == ALL)
    {
      while (++id_collector < g_gc.sub_collectors)
	gfree(id_collector);
      return ;
    }
  iterator = g_gc.mallocated[id_collector]->front;
  while (iterator)
    {
      free(iterator->data);
      tmp = iterator;
      iterator = iterator->next;
      if (tmp)
	pop(g_gc.mallocated[id_collector], tmp);
    }
}

void			clear_created(int id_collector)
{
  t_list_elem		*iterator;
  t_list_elem		*tmp;
  t_garbage_elem	*elem;

  if (id_collector == ALL)
    {
      while (++id_collector < g_gc.sub_collectors)
	clear_created(id_collector);
      return ;
    }
  iterator = g_gc.created[id_collector]->front;
  while (iterator)
    {
      elem = iterator->data;
      elem->destroyer(elem->data);
      free(iterator->data);
      tmp = iterator;
      iterator = iterator->next;
      if (tmp)
	pop(g_gc.created[id_collector], tmp);
    }
}

void			clear_gc(int id_collector)
{
  clear_created(id_collector);
  gfree(id_collector);
}

void			end_gc()
{
  int			i;

  clear_gc(ALL);
  i = 0;
  while (i < g_gc.sub_collectors)
    {
      free_list(g_gc.mallocated[i]);
      free_list(g_gc.created[i]);
      i++;
    }
  free(g_gc.mallocated);
  free(g_gc.created);
}
