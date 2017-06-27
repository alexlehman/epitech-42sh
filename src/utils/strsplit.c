/*
** strsplit.c for 42sh in /Users/arthur/Dev/B2/PSU/PSU_2016_42sh/src/utils/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Sat Apr 22 22:40:21 2017 Arthur Chaloin
** Last update Thu May 18 23:39:18 2017 Paul Laffitte
*/
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int		my_str_contain(char *str, char to_find)
{
  int		index;

  index = 0;
  while (str[index])
    {
      if (str[index] == to_find)
	return (index);
      index += 1;
    }
  return (-1);
}

static int	count_tokens(char *str, char *sep)
{
  int		index;
  int		count;

  index = 0;
  count = 0;
  while (str[index] != 0)
    {
      if (my_str_contain(sep, str[index]) != -1 &&
	  index != 0 && my_str_contain(sep, str[index - 1]) == -1)
	count += 1;
      index += 1;
    }
  if (index != 0 && my_str_contain(sep, str[index - 1]) == -1)
    count += 1;
  return (count);
}

char	**strsplit(char *str, char *sep)
{
  int	count;
  int	index;
  char	**tokens;
  char	*_str;

  if (!(_str = strdup(str)))
    return (NULL);
  count = count_tokens(_str, sep);
  if (!(tokens = malloc(sizeof(char *) * (count + 1))))
    return (NULL);
  tokens[count] = NULL;
  if (count != 0)
    {
      if (!(tokens[0] = strdup(strtok(_str, sep))))
	return (NULL);
      index = 1;
      while (index < count)
	{
	  if (!(tokens[index] = strdup(strtok(NULL, sep))))
	    return (NULL);
	  index += 1;
	}
    }
  free(_str);
  return (tokens);
}
