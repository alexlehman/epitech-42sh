/*
** init.c for 42sh in /Users/arthur/Dev/B2/PSU/PSU_2016_42sh/src/init/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Sat Apr 22 22:07:44 2017 Arthur Chaloin
** Last update Sun May 21 22:46:40 2017 Arthur Chaloin
*/
#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "sh.h"
#include "error.h"
#include "utils.h"
#include "builtin.h"
#include "my.h"

static void		load_history(t_sh *sh)
{
  char			*tmp;
  char			*str;
  size_t		size;
  FILE			*file;

  str = NULL;
  sh->history = NULL;
  tmp = NULL;
  asprintf(&tmp, "%s/.42sh_history", getenv("HOME"));
  if (!(file = fopen(tmp, "r")))
    return;
  while (getline(&str, &size, file) != -1)
    {
      str[strlen(str) - 1] = 0;
      set_history(sh, str);
    }
  history(sh, 0, NULL);
  fclose(file);
}

void		collect_binaries(t_map *bin, DIR *dir, char *path)
{
  char		*name;
  char		*full;
  struct dirent	*actual_file;
  struct stat	info;

  while ((actual_file = readdir(dir)))
    {
      full = NULL;
      name = strdup(actual_file->d_name);
      asprintf(&full, "%s%s", path, name);
      lstat(full, &info);
      if (S_ISDIR(info.st_mode) || !(info.st_mode & S_IXUSR) || name[0] == '.')
	continue;
      map_add(bin, full, name);
    }
}

int	sh_init(t_sh *sh)
{
  int	index;
  DIR	*dir;

  sh->ret = -1;
  if (!getenv("PATH"))
    setenv("PATH", "/bin:/usr/bin:/usr/local/bin", false);
  if (!(sh->path = strsplit(getenv("PATH"), ":")))
    werror(E_MALLOC_FAIL, NULL, true);
  sh->bin = create_map(NULL, 0);
  signal(SIGSEGV, &sigsegv_handler);
  my_register(sh->bin, (void (*)(void *))&free_map, 0);
  index = -1;
  while (sh->path[++index])
    {
      asprintf(&sh->path[index], "%s/", sh->path[index]);
      if ((dir = opendir(sh->path[index])))
	{
	  collect_binaries(sh->bin, dir, sh->path[index]);
	  closedir(dir);
	}
    }
  load_history(sh);
  sh->alias = create_list(LINKED_LIST);
  return (EXIT_SUCCESS);
}

// builtin_source(sh, (char *[]) {"source", "42shrc", NULL});
