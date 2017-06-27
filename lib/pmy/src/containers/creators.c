/*
** creators.c for libmy in /home/onehandedpenguin/Dev/libmy/src/containers/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Sun Jan  8 22:04:58 2017 Paul Laffitte
** Last update Wed Jan 18 16:26:42 2017 Paul Laffitte
*/

#include "my/containers/my_list.h"
#include "my/containers/my_map.h"
#include "my/utils/memory.h"

t_list		*create_list_gc(t_type_list type, int id_collector)
{
  t_list	*list;

  if ((list = create_list(type)))
    my_register(list, (t_destroyer)&free_list, id_collector);
  return (list);
}

t_map		*create_map_gc(t_hash_func hash_func, unsigned int size,
			       int id_collector)
{
  t_map		*map;

  if ((map = create_map(hash_func, size)))
    my_register(map, (t_destroyer)&free_map, id_collector);
  return (map);
}
