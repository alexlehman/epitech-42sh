/*
** s_calc_data.h for addInf in /home/arbona/CPool/CPool_infinadd
**
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
**
** Started on  Mon Oct 24 18:48:08 2016 Thomas Arbona
** Last update Fri Nov  4 11:07:54 2016 Arthur Chaloin
*/

#ifndef INFIN_ADD_H_
# define INFIN_ADD_H_

typedef struct	s_calc_data
{
  char		*result;
  int		curr;
  int		retained;
  int		isneg;
  int		iterator;
  int		cursor;
  int		length;
}		t_calc_data;

int	init_calc_data(t_calc_data *, char *);
void	normalize(char **, char **);
void	delete_sign(char *, char *);
int	max_abs(char *, char *);
int	is_valid_strnbr(char *);
char	*infin_add(char *, char *);

#endif /* !INFIN_ADD_H_ */
