/*
** my_putstr.c for my_putstr in /home/arbona/CPool/CPool_Day04
** 
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
** 
** Started on  Thu Oct  6 08:45:27 2016 Thomas Arbona
** Last update Tue Oct 11 10:36:32 2016 Thomas Arbona
*/

void	my_putchar(char c);

int	my_putstr(char *str)
{
  int	iterator;

  iterator = 0;
  while (str[iterator] != '\0')
    {
      my_putchar(str[iterator]);
      iterator += 1;
    }
  return (0);
}
