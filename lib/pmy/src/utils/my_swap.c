/*
** my_swap.c for my_swap in /home/OneHandedPenguin/CPool_Day04
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Thu Oct  6 13:10:06 2016 Paul Laffitte
** Last update Tue Nov 29 17:44:02 2016 Paul Laffitte
*/

int	my_swap(int *a, int *b)
{
  int	c;

  c = *a;
  *a = *b;
  *b = c;
  return (0);
}

int	my_swap_ptr(void **a, void **b)
{
  void	*c;

  c = *a;
  *a = *b;
  *b = c;
  return (0);
}
