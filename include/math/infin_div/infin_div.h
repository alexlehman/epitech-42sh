/*
** infin_div.h for bistro-matic.h in /home/arthur/Documents/Piscine/Projects/CPool_bistro-matic/include/infin_div/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Wed Nov  2 15:42:37 2016 John Doe
** Last update Fri Nov  4 11:08:33 2016 Arthur Chaloin
*/

#ifndef INFIN_DIV_H_
# define INFIN_DIV_H_

typedef struct	s_div_result
{
  char		*quotient;
  char		*rest;
}		t_div_result;

typedef struct	s_division_data
{
  int		index;
  char		*divisor;
  char		*dividend;
  int		dividend_isneg;
  int		len_divid;
  int		flag_div;
  int		result_is_neg;
  char		*tmp;
  t_div_result	*result;
}		t_division_data;

t_div_result		*infin_div(char *n1, char *n2);
t_division_data		*init_div_data(char *n1, char *n2);
void			set_rest(t_division_data *data);
void			get_result_sign(t_division_data *data);

#endif /* !INFIN_DIV_H_ */
