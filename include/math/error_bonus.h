/*
** error.h for bistro-matic in /home/arthur/Documents/Piscine/Projects/CPool_bistro-matic/bonus/include/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Sun Nov  6 12:21:02 2016 Arthur Chaloin
** Last update Sun Nov  6 12:30:19 2016 Arthur Chaloin
*/

#ifndef ERROR_BONUS_H_
# define ERROR_BONUS_H_

typedef struct	s_error_data
{
  int		index;
  int		lvl;
  int		args_nb;
  char		*name;
  char		**args;
}		t_error_data;

#endif /* !ERROR_BONUS_H_ */
