/*
** command.h for mysh in /home/arthur/B2/PSU/PSU_2016_minishell2/include/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Tue Mar 21 14:50:02 2017 Arthur Chaloin
** Last update Thu May 18 14:48:55 2017 Arthur Chaloin
*/

#ifndef COMMAND_H_
# define COMMAND_H_

# include "sh.h"

typedef struct		s_node
{
  char			*op;
  char			**action;
  struct s_node		*left;
  struct s_node		*right;
}			t_node;

typedef struct		s_op
{
  char			*op;
  int			(*func)(t_sh *, t_node *, t_fd);
}			t_op;

typedef struct		s_command
{
  char			*raw;
  t_node		*start;
}			t_command;

int	command_check(char *command);
int	command_parse(t_sh *sh, t_command *command, char *raw_input);
int	command_execute(t_sh *sh, t_command *command);
int	command_read(t_sh *sh, t_node *actual, t_fd fd);

int	op_and(t_sh *sh, t_node *node, t_fd fd);
int	op_or(t_sh *sh, t_node *node, t_fd fd);
int	op_pipe(t_sh *sh, t_node *node, t_fd fd);
int	op_r_right(t_sh *sh, t_node *node, t_fd fd);
int	op_r_2right(t_sh *sh, t_node *node, t_fd fd);
int	op_r_left(t_sh *sh, t_node *node, t_fd fd);
int	op_r_2left(t_sh *sh, t_node *node, t_fd fd);

#endif /* !COMMAND_H_ */
