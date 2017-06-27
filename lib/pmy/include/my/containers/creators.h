/*
** creators.h for libmy in /home/onehandedpenguin/Dev/libmy/include/my/graphic/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Sun Jan  8 20:59:23 2017 Paul Laffitte
** Last update Wed Jan 18 17:30:55 2017 Paul Laffitte
*/

#ifndef CONTAINERS_CREATORS_H_
# define CONTAINERS_CREATORS_H_

t_list	*create_list_gc(t_type_list type, int id_collector);
t_map	*create_map_gc(t_hash_func hash_func, unsigned int size,
		       int id_collector);

#endif /* !CONTAINERS_CREATORS_H_ */
