/*
** my_map.c for map in /home/onehandedpenguin/mylib/
**
** Made by Paul Laffitteaffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Thu Nov  3 17:22:37 2016 Paul Laffitteaffitte
** Last update Fri Apr 28 20:32:55 2017 Arthur Chaloin
*/

#include "my/containers/my_map.h"

static int	put_in_map(t_map *map, t_map_item *item)
{
  int		id;

  if (map_get(map, item->key) != NULL)
    return (ERROR_84);
  id = MAP_GET_ID(map, item->key);
  if (map->items[id] == NULL)
    {
      map->items[id] = create_list(LINKED_LIST);
      map->empty_slots -= 1;
    }
  if (push_back(map->items[id], item) == ERROR_84)
    return (ERROR_84);
  return (0);
}

static int	reorganize_map(t_map *map)
{
  int		i;
  t_list_elem	*list_elem;

  i = 0;
  while (i < map->size)
    {
      if (map->items[i] != NULL)
	clear_list(map->items[i]);
      i += 1;
    }
  list_elem = map->list_keys->front;
  while (list_elem)
    {
      if (put_in_map(map, (t_map_item*)list_elem->data) == ERROR_84)
	return (ERROR_84);
      list_elem = list_elem->next;
    }
  return (0);
}

/*!
** \brief Enlarge the array of an hashmap
** \param map Pointer on the map
** \param enlarge Number of emplacement to add in the map's array
** \return 0 if everything was fine, 84 if an error occured
** \author Paul Laffitte
**
** Reallocate hashmap's array, keeping all the previous datas but reorganized
** and adding the number of emplacement asked.
*/
static int	enlarge_map(t_map *map, int enlarge)
{
  t_list	**items;
  t_list	**old_items;
  int		i;

  if (!(items = malloc(sizeof(t_list*) * (map->size + enlarge))))
    return (ERROR_84);
  i = 0;
  while (i < map->size)
    {
      items[i] = map->items[i];
      i += 1;
    }
  i = 0;
  while (i < enlarge)
    {
      items[i + map->size] = NULL;
      i += 1;
    }
  old_items = map->items;
  map->items = items;
  map->size += enlarge;
  map->empty_slots = map->size;
  free(old_items);
  reorganize_map(map);
  return (0);
}

/*!
** \brief Create an hashmap
** \param hash_func Pointer on the function used to hash the keys
** \return The newly created hashmap
** \author Paul Laffitte
**
** Create an empty hashmap with an array of item.
** By default, the size of the array is defined by DEFAULT_MAP_SIZE.
** The map use by default <my_string_hash>"("<void *data, unsigned long int max>")" to hash the keys
** or the function passed as parameter if the pointer is not NULL.
*/
t_map		*create_map(t_hash_func hash_func, unsigned int size)
{
  t_map		*map;

  if (!(map = malloc(sizeof(t_map))))
    return (ERROR_NULL);
  map->size = 0;
  map->items = NULL;
  map->list_keys = create_list(LINKED_LIST);
  map->empty_slots = 0;
  if (!(map->hash_func = hash_func))
    map->hash_func = (t_hash_func)&my_string_hash;
  if (enlarge_map(map, size == 0 ? DEFAULT_MAP_SIZE : size) == ERROR_84)
    return (ERROR_NULL);
  return (map);
}

/*!
** \brief Add a data in an hashmap
** \param map Map to add an item inside
** \param data String to add
** \key Key associated to the datd to identify it
** \return 0 if everything was fine, 84 if an error occured
** \author Paul Laffitte
**
** Add a data into the array of the given map, associating it to his key.
** If there is already a data with the same hashed key, add the data in a chained list.
** If the array is not large enough, double his size with <enlarge_map>"("<t_map *map, int enlarge>")".
*/
int		map_add(t_map *map, void *data, const char *key)
{
  t_map_item	*item;

  if (map->empty_slots == 0)
    {
      if (enlarge_map(map, map->size) == ERROR_84)
	return (ERROR_84);
    }
  if (!(item = malloc(sizeof(t_map_item))))
    return (ERROR_84);
  item->data = data;
  item->key = strdup(key);
  if (put_in_map(map, item) == ERROR_84
      || push_back(map->list_keys, strdup(key)) == ERROR_84)
    {
      free(item->key);
      free(item);
      return (ERROR_84);
    }
  return (0);
}
