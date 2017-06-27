/*
** my_strcapitalize.c for my_strcapitalize in /home/arbona/CPool/CPool_Day06
** 
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
** 
** Started on  Mon Oct 10 18:41:00 2016 Thomas Arbona
** Last update Mon Oct 10 18:52:07 2016 Thomas Arbona
*/

char	*my_strcapitalize(char *str)
{
  int	iterator;

  iterator = 0;
  while (str[iterator] != '\0')
    {
      if (iterator == 0
	  && 'a' <= str[iterator]
	  && str[iterator] <= 'z')
	str[iterator] -= 32;
      else if ((str[iterator] == ' '
	       || str[iterator] == '+'
	       || str[iterator] == '-')
	       && 'a' <= str[iterator + 1]
	       && str[iterator + 1] <= 'z')
	str[iterator + 1] -= 32;
      iterator += 1;
    }
  return (str);
}
