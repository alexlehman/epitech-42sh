/*
** my_strupcase.c for my_strupcase in /home/arbona/CPool/CPool_Day06
** 
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
** 
** Started on  Mon Oct 10 18:20:15 2016 Thomas Arbona
** Last update Mon Oct 10 18:34:04 2016 Thomas Arbona
*/

char	*my_strupcase(char *str)
{
  int	iterator;

  iterator = 0;
  while (str[iterator] != '\0')
    {
      if ('a' <= str[iterator] && str[iterator] <= 'z')
	str[iterator] -= 32;
      iterator += 1;
    }
  return (str);
}
