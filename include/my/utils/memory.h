/*
** memory.h for libmy in /home/onehandedpenguin/Dev/lib"my/include/utils/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Wed Dec 21 00:21:07 2016 Paul Laffitte
** Last update Fri Apr 28 22:21:07 2017 Arthur Chaloin
*/

#ifndef MEMORY_H_
# define MEMORY_H_

# include <unistd.h>

# include "my/containers/garbage.h"

int	my_register(void *data, t_destroyer destroyer, int id_collector);
int	my_swap(int *a, int *b);
int	my_swap_ptr(void **a, void **b);
void	*galloc(size_t size);
int	my_register_memory(void *memory, int id_collector);

#endif /* !MEMORY_H_ */
