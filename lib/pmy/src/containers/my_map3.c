/*
** my_map3.c for libmy in /home/onehandedpenguin/Dev/libmy/src/containers/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Wed Jan 18 14:28:45 2017 Paul Laffitte
** Last update Thu Jan 19 00:03:27 2017 Paul Laffitte
*/

#include "my/containers/my_map.h"

static void	free_list_keys(t_map *map)
{
  t_list_elem	*iterator;

  iterator = map->list_keys->front;
  while (iterator)
    {
      free(iterator->data);
      iterator = iterator->next;
    }
  free_list(map->list_keys);
}

void		free_map(t_map *map)
{
  int		i;
  t_list	*all;
  t_list_elem	*iterator;

  all = map_get_all(map);
  iterator = all->front;
  while (iterator)
    {
      free(((t_map_item*)iterator->data)->key);
      free(iterator->data);
      iterator = iterator->next;
    }
  free_list(all);
  i = 0;
  while (i < map->size)
    {
      if (map->items[i])
	free_list(map->items[i]);
      i += 1;
    }
  free_list_keys(map);
  free(map->items);
  free(map);
}

t_list		*map_get_all(t_map *map)
{
  t_list	*all;
  t_map_item	*item;
  t_list_elem	*tmp;
  t_list_elem	*iterator;

  if ((all = create_list(LINKED_LIST)) == ERROR_NULL)
    return (ERROR_NULL);
  iterator = map->list_keys->front;
  while (iterator)
    {
      tmp = iterator;
      iterator = iterator->next;
      if (!(item = map_get_item(map, tmp->data)))
	{
	  free(tmp->data);
	  pop(map->list_keys, tmp);
	}
      else
	push_back(all, item);
    }
  return (all);
}
