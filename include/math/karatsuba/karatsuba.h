/*
** karabatsu.h for karabatsu in /home/arbona/CPool/CPool_bistro-matic/include/karabatsu/
**
** Made by Thomas Arbona
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Nov  1 11:49:03 2016 Thomas Arbona
** Last update Tue Nov  1 16:16:39 2016 Thomas Arbona
*/

#ifndef KARATSUBA_H_
# define KARATSUBA_H_

typedef struct	s_karatsuba_data
{
  char		*a;
  char		*b;
  char		*c;
  char		*d;
  char		*ab;
  char		*ac;
  char		*cd;
  char		*bd;
  char		*ad_p_bc;
  char		*result;
  int		isneg;
  int		n;
}		t_karatsuba_data;

char	*karatsuba(char *, char *);
char	*split(char *, int, char **, char **);
int	krtsb_del_sign(char **, int);
char	*shift_nb(char *, int);

#endif	/* !KARATSUBA_H_ */
