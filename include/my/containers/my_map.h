/*
** my_map.h for libmy in /home/onehandedpenguin/mylib/include/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Fri Nov  4 00:02:39 2016 Paul Laffitte
** Last update Fri Apr 28 20:33:32 2017 Arthur Chaloin
*/

#ifndef MY_MAP_H_
# define MY_MAP_H_
# define DEFAULT_MAP_SIZE 30000

/*!
** \brief Get the id of an item
** \param map Map is which get the id
** \param key Key
** \return The first id where the item corresponding to the key might be located
** \author Paul Laffitte
**
** Get the theorical id of an item.
** If the hash of the item key is conflicting with another, is possible that
** item is not located at this place but at one of the following ids.
*/
# define MAP_GET_ID(map, key) (map->hash_func(key, map->size))

# include <stdlib.h>
# include <string.h>
# include "my/containers/my_list.h"
# include "my/utils/hash.h"
# include "my/utils/errors.h"

/*!
** \struct s_item
** \brief Item of an hashmap
** \author Paul Laffitte
**
** Contain a list of data with the same hashed key and his key
*/
typedef struct		s_map_item
{
  void			*data;
  char			*key;
}			t_map_item;

/*!
** \struct s_map
** \brief Hashmap
** \author Paul Laffitte
**
** Contain an array of his items,
** the number of items contained,
** the size of his array's items,
** and a pointer to the function used to hash the keys.
*/
typedef struct		s_map
{
  t_list		**items;
  t_list		*list_keys;
  int			empty_slots;
  int			size;
  t_hash_func		hash_func;
}			t_map;

t_map			*create_map(t_hash_func hash_func, unsigned int size);
int			map_add(t_map *map, void *data, const char *key);

t_map_item		*map_get_item(const t_map *map, char *key);
void			*map_get(const t_map *map, char *key);
int			map_replace(t_map *map, void *data, char *key);
int			map_remove(t_map *map, char *key);

void			free_map(t_map *map);
t_list			*map_get_all(t_map *map);

#endif /* !MY_MAP_H_ */
