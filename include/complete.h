/*
** complete.h for 42sh in /Users/arthur/Documents/Dev/B2/PSU/PSU_2016_42sh/include/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Thu May  4 09:47:44 2017 Arthur Chaloin
** Last update Thu May  4 10:04:48 2017 Arthur Chaloin
*/

#ifndef COMPLETE_H_
# define COMPLETE_H_

void	auto_complete(t_sh *sh, char **cmd);
int	match(char *s1, char *s2);
void	complete(char **cmd, char *last);
void	select_op(char **cmd, t_list *list);
t_list	*complete_dir(char **command);

#endif /* !COMPLETE_H_ */
