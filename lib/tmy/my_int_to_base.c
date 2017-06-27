/*
** my_int_to_base.c for my_int_to_base in /home/onehandedpenguin/CPool_bistro-matic/lib/my/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Sat Nov  5 17:20:37 2016 Paul Laffitte
** Last update Sun Nov  6 14:53:58 2016 Paul Laffitte
*/
#include <stdlib.h>

char	*convert_base(char *, char *, char *);

int	my_power_rec(int nb, int p);

static int	intlen(int nb)
{
  int		isneg;
  long int	i;

  if (nb == 0)
    return (1);
  else if (nb == -2147483648)
    return (11);
  if ((isneg = (nb < 0)) != 0)
    nb *= -1;
  i = 0;
  while (my_power_rec(10, i++) <= nb);
  return (isneg ? i : i - 1);
}

static void	int_to_str(int nb, char *nb_str)
{
  if (nb < 0)
    *nb_str = '-';
  if (nb / 10 != 0)
    int_to_str((nb < 0 ? nb / 10 * -1 : nb / 10), &nb_str[-1]);
  nb_str[0] = '0' + (nb < 0 ? nb % 10 * -1 : nb % 10);
}

char	*my_int_to_str(int nb)
{
  int	len;
  char	*nb_str;

  len = intlen(nb);
  if (!(nb_str = malloc(sizeof(char) * (len + 1))))
    return (NULL);
  int_to_str(nb, &nb_str[len - 1]);
  nb_str[len] = '\0';
  return (nb_str);
}

char	*my_int_to_base(int nb, char *base)
{
  return (convert_base(my_int_to_str(nb), "0123456789", base));
}
