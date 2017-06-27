/*
** input.h for 42sh in /Users/arthur/Documents/Dev/B2/PSU/PSU_2016_42sh/include/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Tue May  2 17:13:34 2017 Arthur Chaloin
** Last update Tue May  2 19:28:24 2017 Arthur Chaloin
*/

#ifndef INPUT_H_
# define INPUT_H_

# include "sh.h"

# define I_SET_IPT	1
# define I_SET_CURS	2

# define ESCAPE '\33'
# define BACKSPACE '\177'

int	get_input(t_sh *sh, char **buff);
void	update_input(char **input, char buffer, const int mode);

#endif /* !INPUT_H_ */
