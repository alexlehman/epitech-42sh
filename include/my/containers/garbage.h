/*
** garbage.h for libmy in /home/onehandedpenguin/Dev/libmy/include/my/containers/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Wed Jan  4 01:43:14 2017 Paul Laffitte
** Last update Fri Apr 28 21:04:35 2017 Arthur Chaloin
*/

#ifndef GARBAGE_H_
# define GARBAGE_H_

# include "my/containers/my_list.h"
# define ALL -1

# define GC_USE(n)	g_gc.actual_group = n;

typedef struct			s_gc
{
  int				actual_group;
  int				sub_collectors;
  t_list			**mallocated;
  t_list			**created;
}				t_gc;

typedef void			(*t_destroyer)(void *data);

typedef struct			s_garbage_elem
{
  void				*data;
  t_destroyer			destroyer;
}				t_garbage_elem;

extern t_gc	g_gc;

int				init_gc(int sub_collectors);
void				gfree(int id_collector);
void				clear_created(int id_collector);
void				clear_gc(int id_collector);
void				end_gc();

#endif/* !GARBAGE_H_ */
