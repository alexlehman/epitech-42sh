/*
** my_strlen.c for my_strlen in /home/arbona/CPool/CPool_Day04
** 
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
** 
** Started on  Thu Oct  6 08:51:35 2016 Thomas Arbona
** Last update Thu Oct  6 08:52:48 2016 Thomas Arbona
*/

int	my_strlen(char *str)
{
  int	count;

  count = 0;
  while (str[count] != '\0')
    count += 1;
  return (count);
}
