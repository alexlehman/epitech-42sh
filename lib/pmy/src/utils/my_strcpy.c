/*
** my_strcpy.c for 42sh in /home/onehandedpenguin/Dev/PSU_2016/PSU_2016_42sh/lib/my/src/utils/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Sat May 20 00:04:47 2017 Paul Laffitte
** Last update Sat May 20 00:04:52 2017 Paul Laffitte
*/

#include <stdlib.h>

char	*my_strcpy(char *dest, const char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
