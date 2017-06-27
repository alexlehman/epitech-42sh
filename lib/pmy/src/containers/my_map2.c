/*
** my_map2.c for map in /home/onehandedpenguin/Dev/mylib/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Mon Nov 14 11:06:57 2016 Paul Laffitte
** Last update Fri Apr 28 20:34:31 2017 Arthur Chaloin
*/

#include "my/containers/my_map.h"

static int		map_finder(t_list *list, t_list_elem *list_elem,
				   void *finder)
{
  (void)list;
  if (strcmp(((t_map_item*)list_elem->data)->key,
		(char*)((t_list_finder*)finder)->data) == 0)
    push_back(((t_list_finder*)finder)->found, list_elem->data);
  return (0);
}

t_map_item		*map_get_item(const t_map *map, char *key)
{
  int			id;
  t_list		*list_results;
  t_list_elem		*result;
  t_list_finder		finder;
  t_map_item		*item;

  finder.data = key;
  if (!map->items[(id = MAP_GET_ID(map, key))])
    return (ERROR_NULL);
  list_results = find(map->items[id],
		      &map_finder, &finder);
  result = list_results->front;
  item = NULL;
  if (result != NULL)
    item = result->data;
  free_list(list_results);
  return (item);
}

/*!
** \brief Get a data from a map
** \param map Map in which search
** \param key Key corresponding to the wanted data
** \return The data corresponding to the given key
** \author Paul Laffitte
**
** Get the content of the item associated to the given key in the given map.
*/
void			*map_get(const t_map *map, char *key)
{
  t_map_item		*item;

  if (!(item = map_get_item(map, key)))
    return (ERROR_NULL);
  return (item->data);
}

int			map_replace(t_map *map, void *data, char *key)
{
  t_map_item		*item;

  if (!(item = map_get_item(map, key)))
    return (ERROR_84);
  item->data = data;
  return (0);
}

int			map_remove(t_map *map, char *key)
{
  int			id;
  t_list_elem		*iterator;

  id = MAP_GET_ID(map, key);
  if (!map->items[id])
    return (ERROR_84);
  iterator = map->items[id]->front;
  while (iterator && strcmp(((t_map_item*)iterator->data)->key, key) != 0)
    iterator = iterator->next;
  if (!iterator)
    return (ERROR_84);
  free(((t_map_item*)iterator->data)->key);
  free(((t_map_item*)iterator->data));
  pop(map->items[id], iterator);
  return (0);
}
