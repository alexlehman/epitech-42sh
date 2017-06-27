/*
** exec.c for mysh in /home/arthur/B2/PSU/PSU_2016_minishell2/src/core/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Tue Mar 21 15:27:31 2017 Arthur Chaloin
** Last update Thu May 18 14:10:26 2017 Arthur Chaloin
*/
#include <string.h>
#include "sh.h"
#include "command.h"

t_op	op_tab[] = {
  {"&&", &op_and},
  {"||", &op_or},
  {"|", &op_pipe},
  {"<", &op_r_left},
  {">", &op_r_right},
  {"<<", &op_r_2left},
  {">>", &op_r_2right}
};

int	command_read(t_sh *sh, t_node *actual, t_fd fd)
{
  int	idx;

  if (actual->op)
    {
      if (!strcmp(";", actual->op))
	{
	  command_read(sh, actual->left, fd);
	  return (command_read(sh, actual->right, fd));
	}
      else
	{
	  idx = -1;
	  while (op_tab[++idx].op && strcmp(actual->op, op_tab[idx].op));
	  return (op_tab[idx].func(sh, actual, fd));
	}
    }
  else
    return (sh_execute(sh, actual->action, fd));
}

int	command_execute(t_sh *sh, t_command *command)
{
  return (command_read(sh, command->start, (t_fd) {0, 1}));
}
