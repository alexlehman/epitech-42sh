/*
** my_malloc.c for libmy in /home/onehandedpenguin/Dev/lib"my/src/utils/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Wed Dec 21 00:50:07 2016 Paul Laffitte
** Last update Sun May 21 18:37:11 2017 Arthur Chaloin
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my/utils/errors.h"
#include "my/containers/my_list.h"
#include "my/containers/garbage.h"

void			*galloc(size_t size)
{
  void			*memory;

  if (!(memory = malloc(size))
      || push_back(g_gc.mallocated[g_gc.actual_group], memory) == ERROR_84)
    {
      fprintf(stderr, "fail malloc");
      exit(1);
    }
  return (memory);
}

int			my_register_memory(void *memory, int id_collector)
{
  if (push_back(g_gc.mallocated[id_collector], memory) == ERROR_84)
    return (ERROR_84);
  return (0);
}

int			my_register(void *data, t_destroyer destroyer,
				    int id_collector)
{
  t_garbage_elem	*elem;

  if (!(elem = malloc(sizeof(t_garbage_elem)))
      || push_back(g_gc.created[id_collector], elem) == ERROR_84)
    {
      my_print_err("fail malloc");
      return (ERROR_84);
    }
  elem->data = data;
  elem->destroyer = destroyer;
  return (0);
}
