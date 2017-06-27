/*
** my_tablen.c for my in /home/arbona/CPool/CPool_bistro-matic/lib/my/
**
** Made by Thomas Arbona
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Wed Nov  2 19:37:48 2016 Thomas Arbona
** Last update Wed Nov  2 19:38:46 2016 Thomas Arbona
*/
#include <unistd.h>

int	my_tablen(char **tab)
{
  int	count;

  count = 0;
  while (tab[count] != NULL)
    count += 1;
  return (count);
}
