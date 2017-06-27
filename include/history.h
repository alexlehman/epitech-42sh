/*
** history.h for 42sh in /Users/arthur/Documents/Dev/B2/PSU/PSU_2016_42sh/include/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Tue May  2 19:02:12 2017 Arthur Chaloin
** Last update Tue May  2 19:10:02 2017 Arthur Chaloin
*/

#ifndef HISTORY_H_
# define HISTORY_H_

typedef struct s_sh	t_sh;

typedef struct		s_history
{
  char			*command;
  struct s_history	*prev;
  struct s_history	*next;
}			t_history;

void	history(t_sh *sh, int entry, char **command);
void	set_history(t_sh *sh, char *command);
void	save_history(t_sh *sh);

#endif /* !HISTORY_H_ */
