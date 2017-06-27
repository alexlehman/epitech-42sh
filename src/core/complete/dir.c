/*
** dir.c for mysh in /home/arthur/B2/PSU/PSU_2016_minishell2/bonus/src/core/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Sat Apr  8 14:31:34 2017 Arthur Chaloin
** Last update Sat May 20 00:24:35 2017 Arthur Chaloin
*/
#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include "sh.h"
#include "complete.h"
#include "my.h"

char		*split_chain(char *str, int side)
{
  int		index;

  index = strlen(str);
  while (index >= 0 && str[index] != '/')
    index--;
  if (side)
    return (strdup(str + index + 1));
  else if (index >= 0)
    return (strndup(str, index + 1));
  else
    return (strdup("./"));
}

static void	get_list(t_list *list, char *path, char *actual)
{
  DIR		*dir;
  struct dirent	*actual_file;
  char		*tmp;
  char		*tmp2;
  struct stat	info;

  if (!(dir = opendir(path)))
    return;
  while ((actual_file = readdir(dir)))
    {
      asprintf(&tmp, "%s*", actual);
      if (actual_file->d_name[0] != '.' && match(actual_file->d_name, tmp))
	{
	  tmp2 = NULL;
	  asprintf(&tmp2, "%s/%s", path, actual_file->d_name);
	  lstat(tmp2, &info);
	  asprintf(&tmp2, (S_ISDIR(info.st_mode)) ? "%s/" : "%s",
		   actual_file->d_name);
	  push_back(list, tmp2);
	}
    }
  closedir(dir);
}

t_list		*complete_dir(char **command)
{
  t_list	*list;

  list = create_list(LINKED_LIST);
  get_list(list,
	   split_chain(*command, 0),
	   split_chain(*command, 1));
  return (list);
}
