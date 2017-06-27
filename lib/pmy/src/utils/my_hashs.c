/*
** my_no_hash.c for my_no_hash in /home/onehandedpenguin/mylib/hash/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Thu Nov  3 23:35:43 2016 Paul Laffitte
** Last update Fri Apr 28 20:37:41 2017 Arthur Chaloin
*/

#include <stdlib.h>
#include <string.h>

unsigned long int	my_hash(void *data, size_t size,
				unsigned long int max)
{
  unsigned long int	hash;
  char			*casted_data;
  size_t		i;

  casted_data = data;
  hash = 42;
  i = 0;
  while (i < size)
    {
      hash = (hash * casted_data[i] - casted_data[i]) % max;
      i++;
    }
  return (hash);
}

unsigned long int	my_string_hash(char *data,
				       unsigned long int max)
{
  return (my_hash(data, strlen(data), max));
}

unsigned long int	my_char_hash(char *data,
				       unsigned long int max)
{
  return (my_hash(data, sizeof(char), max));
}
