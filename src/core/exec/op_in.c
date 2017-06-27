/*
** redir.c for mysh in /home/arthur/B2/PSU/PSU_2016_minishell2/src/core/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Wed Apr  5 19:26:46 2017 Arthur Chaloin
** Last update Tue May  2 13:28:15 2017 Arthur Chaloin
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "sh.h"
#include "command.h"
#include "error.h"

static int	get_mult_fd(t_node *node)
{
  int	ffd;

  if (!strcmp(node->right->op, ">"))
    {
      if ((ffd = open(node->right->right->action[0],
			 O_RDWR | O_TRUNC | O_CREAT, 00644)) == -1)
	{
	  werror(E_BAD_MOD, node->right->action[0], false);
	  return (-1);
	}
    }
  else
    {
      if ((ffd = open(node->right->right->action[0],
			 O_RDWR | O_APPEND | O_CREAT, 00644)) == -1)
	{
	  werror(E_BAD_MOD, node->right->action[0], false);
	  return (-1);
	}
    }
  return (ffd);
}

int	op_r_left(t_sh *sh, t_node *node, t_fd fd)
{
  int	ffd[2];
  int	ret;

  ret = 1;
  if (!node->right->op)
    {
      if ((ffd[0] = open(node->right->action[0], O_RDONLY, 00644)) == -1)
	{
	  werror(E_NOT_FOUND, node->right->action[0], false);
	  return (1);
	}
      ret = command_read(sh, node->left, (t_fd) {ffd[0], fd.out});
    }
  else
    {
      if ((ffd[0] = open(node->right->left->action[0], O_RDONLY, 00644)) == -1)
      	{
      	  werror(E_NOT_FOUND, node->right->left->action[0], false);
      	  return (1);
      	}
      if ((ffd[1] = get_mult_fd(node)) == -1)
	return (1);
      ret = command_read(sh, node->left, (t_fd) {ffd[0], ffd[1]});
    }
  return (ret);
}

static char	*get_match(t_node *node)
{
  if (node->right->op)
    return (node->right->left->action[0]);
  else
    return (node->right->action[0]);
}

int		op_r_2left(t_sh *sh, t_node *node, t_fd fd)
{
  unsigned	bytes;
  char		buffer[4096];
  int		pipefd[2];

  pipe(pipefd);
  while (1)
    {
      printf("? ");
      fflush(stdout);
      if ((bytes = read(0, buffer, 4095)) < 1)
	return (1);
      buffer[bytes] = 0;
      if (!strncmp(buffer, get_match(node), bytes - 2))
	{
	  close(pipefd[1]);
	  return (command_read(sh, node->left, (t_fd) {pipefd[0], fd.out}));
	}
      else
	write(pipefd[1], buffer, bytes);
    }
}
