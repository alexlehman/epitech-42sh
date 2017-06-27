/*
** cd.c for mysh in /home/arthur/Documents/B1-Systeme_UNIX/PSU_2016_minishell1/src/builtins/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Wed Jan  4 16:45:50 2017 Arthur Chaloin
** Last update Fri Apr 28 21:55:24 2017 Arthur Chaloin
*/
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "sh.h"
#include "builtin.h"
#include "error.h"

int		builtin_cd(__attribute__((unused))t_sh *sh, char **argv)
{
  int		result;
  char		buffer[4096];
  static char	*prev = NULL;
  struct stat	stat;

  if (!getcwd(buffer, 4096))
    buffer[0] = 0;
  if (argv[1] && argv[1][0] == '-')
    result = chdir(prev);
  else if (argv[1] && argv[1][0] != '-')
    result = chdir(argv[1]);
  else
    result = chdir(getenv("HOME"));
  if (result)
    {
      lstat(argv[1], &stat);
      if (!access(argv[1], F_OK) && !S_ISDIR(stat.st_mode))
	werror(E_NOT_DIR, (argv[1][0] == '-') ? prev : argv[1], false);
      else
	werror(E_NOT_FOUND, (argv[1][0] == '-') ? prev : argv[1], false);
      return (1);
    }
  else if (buffer[0])
    prev = strdup(buffer);
  return (0);
}
