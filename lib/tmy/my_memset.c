/*
** my_memset.c for lib in /home/arthur/Documents/Piscine/Projects/CPool_bistro-matic/lib/my/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Fri Oct 28 15:28:45 2016 Arthur Chaloin
** Last update Fri Oct 28 15:33:33 2016 Arthur Chaloin
*/

void	my_memset(char *str, int size, char c)
{
  int	index;

  index = 0;
  while (index < size)
    {
      str[index] = c;
      index += 1;
    }
  str[size - 1] = '\0';
}
