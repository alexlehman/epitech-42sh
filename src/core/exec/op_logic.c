/*
** op.c for mysh in /home/arthur/B2/PSU/PSU_2016_minishell2/src/core/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Tue Mar 21 19:33:11 2017 Arthur Chaloin
** Last update Thu May 18 14:13:36 2017 Arthur Chaloin
*/
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "sh.h"
#include "command.h"
#include "error.h"
#include "my.h"

int	op_and(t_sh *sh, t_node *node, t_fd fd)
{
  int	ret;

  ret = command_read(sh, node->left, fd);
  if (ret)
    return (ret);
  return (command_read(sh, node->right, fd));
}

int	op_or(t_sh *sh, t_node *node, t_fd fd)
{
  int	ret;

  ret = command_read(sh, node->left, fd);
  if (!ret)
    return (ret);
  return (command_read(sh, node->right, fd));
}
