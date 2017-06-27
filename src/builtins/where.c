/*
** where.c for 42sh in /Users/arthur/Documents/Dev/B2/PSU/PSU_2016_42sh/src/builtins/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Tue May  2 14:59:37 2017 Arthur Chaloin
** Last update Sun May 21 23:08:16 2017 Arthur Chaloin
*/
#define _GNU_SOURCE
#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>
#include "sh.h"
#include "builtin.h"
#include "error.h"

static bool	list_binaries(DIR *dir, char *path, char *token)
{
  bool		found;
  char		*full;
  struct dirent	*actual_file;
  struct stat	info;

  found = false;
  while ((actual_file = readdir(dir)))
    {
      full = NULL;
      asprintf(&full, "%s%s", path, actual_file->d_name);
      lstat(full, &info);
      if (S_ISDIR(info.st_mode)
	  || !(info.st_mode & S_IXUSR)
	  || actual_file->d_name[0] == '.'
	  || strcmp(actual_file->d_name, token))
	continue;
      printf("%s\n", full);
      found = true;
    }
  return (found);
}

static int	search_bin(t_sh *sh, char *name)
{
  bool		builtin;
  int		bin;
  int		index;
  DIR		*dir;

  bin = 0;
  builtin = false;
  index = -1;
  while (builtins[++index].name && strcmp(builtins[index].name, name));
  if (builtins[index].name)
    {
      printf("%s is a shell built-in\n", name);
      builtin = true;
    }
  index = -1;
  while (sh->path[++index])
    {
      if ((dir = opendir(sh->path[index])))
	{
	  bin += list_binaries(dir, sh->path[index], name);
	  closedir(dir);
	}
    }
  return (!(bin || builtin));
}

int		builtin_where(t_sh *sh, char **argv)
{
  int		index;
  int		found;

  index = 0;
  if (!argv[1])
    return (werror(E_MISSING_ARG, argv[0], false));
  while (argv[++index])
    found = search_bin(sh, argv[index]);
  return (found);
}
