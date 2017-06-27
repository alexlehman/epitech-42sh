/*
** error.h for bistro-matic in /home/arthur/Documents/Piscine/Projets/CPool_bistro-matic/include/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Thu Oct 27 16:55:46 2016 Arthur Chaloin
** Last update Sat Nov  5 19:10:36 2016 Thomas Arbona
*/

#ifndef ERROR_H_
# define ERROR_H_

int	check_expr(char *expr);
int	verify(int ac, char **av, int nb_ops);
void	exit_error(int error_nb);

#endif /* !ERROR_H_ */
