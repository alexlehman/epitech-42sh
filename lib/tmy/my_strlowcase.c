/*
** my_strlowcase.c for my_strlowcase in /home/arbona/CPool/CPool_Day06
** 
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
** 
** Started on  Mon Oct 10 18:20:15 2016 Thomas Arbona
** Last update Mon Oct 10 18:36:22 2016 Thomas Arbona
*/

char	*my_strlowcase(char *str)
{
  int	iterator;

  iterator = 0;
  while (str[iterator] != '\0')
    {
      if ('A' <= str[iterator] && str[iterator] <= 'Z')
	str[iterator] += 32;
      iterator += 1;
    }
  return (str);
}
