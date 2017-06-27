/*
** hash.h for libmy in /home/onehandedpenguin/Dev/lib"my/include/utils/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Wed Dec 21 00:38:54 2016 Paul Laffitte
** Last update Thu Jan 19 01:07:01 2017 Paul Laffitte
*/

#ifndef HASH_H_
# define HASH_H_

typedef unsigned long int	(*t_hash_func)(void *data,
				 	       unsigned long int max);

unsigned long int		my_hash(void *data, size_t size,
					unsigned long int max);
unsigned long int		my_string_hash(char *data,
					       unsigned long int max);
unsigned long int		my_char_hash(char *data,
					     unsigned long int max);

#endif /* !HASH_H_ */
