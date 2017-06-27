/*
** launch.c for mysh in /home/arthur/B2/PSU/PSU_2016_minishell2/src/core/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Tue Mar 21 19:14:26 2017 Arthur Chaloin
** Last update Tue May 30 14:18:19 2017 Thomas ARBONA
*/
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "sh.h"
#include "builtin.h"
#include "error.h"
#include "my.h"

t_builtin	builtins[] = {
  {"cd", &builtin_cd},
  {"echo", &builtin_echo},
  {"alias", &builtin_alias},
  {"source", &builtin_source},
  {"repeat", &builtin_repeat},
  {"env", &builtin_env},
  {"setenv", &builtin_setenv},
  {"unsetenv", &builtin_unsetenv},
  {"where", &builtin_where},
  {"which", &builtin_which},
  {"set", &builtin_set},
  {"unset", &builtin_unset},
  {"exit", &builtin_exit},
  {"if", &builtin_if},
  {"while", &builtin_while},
  {"foreach", &builtin_foreach},
  {"read", &builtin_read},
  {NULL, NULL}
};

static int	is_valid(char *command)
{
  struct stat	stat;

  if (!access(command, F_OK))
    {
      lstat(command, &stat);
      if (!access(command, X_OK) && !S_ISDIR(stat.st_mode))
	return (1);
      werror(E_BAD_MOD, command, false);
    }
  else
    werror(E_UNKNOWN_CMD, command, false);
  return (0);
}

static int	core_execute_builtin(t_sh *sh, t_builtin *builtin,
				     char **argv, t_fd fd)
{
  int		ret;
  int		fdsave[2];

  fdsave[0] = dup(0);
  fdsave[1] = dup(1);
  if (fdsave[0] == -1 || fdsave[1] == -1 ||
      dup2(fd.in, 0) == -1 || dup2(fd.out, 1) == -1)
    return (1);
  ret = builtin->func(sh, argv);
  close(fd.in);
  close(fd.out);
  dup2(fdsave[0], 0);
  dup2(fdsave[1], 1);
  return (ret);
}

static int	core_execute_binary(char *bin, char **argv, t_fd fd)
{
  int		status;
  int		fdsave[2];

  fdsave[0] = dup(0);
  fdsave[1] = dup(1);
  if (fdsave[0] == -1 || fdsave[1] == -1 ||
      dup2(fd.in, 0) == -1 || dup2(fd.out, 1) == -1)
    return (1);
  if (!fork())
    {
      if (execve(bin, argv, environ) == -1)
        werror("Exec format error. Binary file not executable.", bin, false);
      end_gc();
      exit(1);
    }
  wait(&status);
  close(fd.in);
  close(fd.out);
  dup2(fdsave[0], 0);
  dup2(fdsave[1], 1);
  if (WIFSIGNALED(status))
    werror_signal(WTERMSIG(status), WCOREDUMP(status));
  return ((WIFEXITED(status)) ? WEXITSTATUS(status) :
	  ((status < 128) ? 128 + status : status));
}

int	sh_execute(t_sh *sh, char **argv, t_fd fd)
{
  int	index;
  char	*bin;

  index = -1;
  while (builtins[++index].name && strcmp(builtins[index].name, argv[0]));
  if (builtins[index].func)
    return (core_execute_builtin(sh, &(builtins[index]), argv, fd));
  bin = (char *)map_get(sh->bin, argv[0]);
  if (bin)
    return (core_execute_binary(bin, argv, fd));
  else if (is_valid(argv[0]))
    return (core_execute_binary(argv[0], argv, fd));
  return (1);
}
