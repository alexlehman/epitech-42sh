/*
** my_isneg.c for my_isneg in /home/arbona/CPool/CPool_Day03
** 
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
** 
** Started on  Wed Oct  5 09:28:27 2016 Thomas Arbona
** Last update Tue Oct 11 10:29:09 2016 Thomas Arbona
*/

void	my_putchar(char c);

int	my_isneg(int n)
{
  if (n < 0)
    my_putchar('N');
  else
    my_putchar('P');
  return (0);
}
