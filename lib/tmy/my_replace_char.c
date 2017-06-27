/*
** replace_char.c for replace_char in /home/onehandedpenguin/CPool_bistro-matic/lib/my/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Fri Nov  4 22:55:22 2016 Paul Laffitte
** Last update Fri Nov  4 22:56:05 2016 Paul Laffitte
*/

int	my_replace_char(char *str, char to_replace, char c)
{
  while (*str != 0)
    {
      if (*str == to_replace)
	*str = c;
      str += 1;
    }
  return (0);
}
