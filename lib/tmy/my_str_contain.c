/*
** my_str_contain.c for lib in /home/arthur/Documents/Piscine/Projects/CPool_bistro-matic/lib/my/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Fri Oct 28 16:42:04 2016 Arthur Chaloin
** Last update Fri Oct 28 16:43:36 2016 Arthur Chaloin
*/

int	my_str_contain(char *str, char to_find)
{
  int	index;

  index = 0;
  while (str[index])
    {
      if (str[index] == to_find)
	return (index);
      index += 1;
    }
  return (-1);
}
