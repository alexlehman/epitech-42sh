/*
** infin_sqrt.h for bistro-matic in /home/onehandedpenguin/CPool_bistro-matic/bonus/include/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Wed Nov  2 18:02:55 2016 Paul Laffitte
** Last update Sun Nov  6 13:56:11 2016 Paul Laffitte
*/

#ifndef INFIN_SQRT_H_
# define INFIN_SQRT_H_

typedef struct	s_dichotomy
{
  char		*low_limit;
  char		*high_limit;
  char		*median;
  char		*first_two_dgt_nb;
  char		*two;
  int		compare;
}		t_dichotomy;

char	*infin_sqrt(char **);

#endif /* !INFIN_SQRT_H_ */
