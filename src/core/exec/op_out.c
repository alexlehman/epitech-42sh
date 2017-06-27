/*
** op.c for mysh in /home/arthur/B2/PSU/PSU_2016_minishell2/src/core/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Tue Mar 21 19:33:11 2017 Arthur Chaloin
** Last update Sat May 20 19:28:44 2017 Arthur Chaloin
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

int		op_pipe(t_sh *sh, t_node *node, t_fd fd)
{
  int		ret;
  int		status;
  int		pipefd[2];
  pid_t		child;

  if (pipe(pipefd) == -1)
    {
      werror(E_PIPE_FAIL, NULL, false);
      return (1);
    }
  if (!(child = fork()))
    {
      close(pipefd[1]);
      ret = command_read(sh, node->right, (t_fd) {pipefd[0], fd.out});
      end_gc();
      exit(ret);
    }
  close(pipefd[0]);
  if ((ret = command_read(sh, node->left, (t_fd) {fd.in, pipefd[1]})))
    return (ret);
  waitpid(child, &status, 0);
  if (WEXITSTATUS(status))
    return (WEXITSTATUS(status));
  return (WEXITSTATUS(status));
}

int	op_r_right(t_sh *sh, t_node *node, t_fd fd)
{
  int	ffd;
  int	ret;

  ret = 1;
  if ((ffd = open(node->right->action[0],
		 O_RDWR | O_TRUNC | O_CREAT, 00644)) == -1)
    werror(E_BAD_MOD, node->right->action[0], false);
  else
    ret = command_read(sh, node->left, (t_fd) {fd.in, ffd});
  return (ret);
}

int	op_r_2right(t_sh *sh, t_node *node, t_fd fd)
{
  int	ffd;
  int	ret;

  ret = 1;
  if ((ffd = open(node->right->action[0],
		 O_RDWR | O_APPEND | O_CREAT, 00644)) == -1)
    werror(E_BAD_MOD, node->right->action[0], false);
  else
    ret = command_read(sh, node->left, (t_fd) {fd.in, ffd});
  return (ret);
}
