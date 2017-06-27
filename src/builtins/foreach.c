/*
** foreach.c for 42sh in /home/antiaskid/Documents/B2/PSU/PSU_2016_42sh/src/builtins/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Sun May 21 18:42:51 2017 Antoine Briaux
** Last update Sun May 21 23:12:35 2017 Arthur Chaloin
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include "sh.h"
#include "input.h"
#include "builtin.h"
#include "error.h"

static int 	foreach_error(char **argv)
{
	int 	nb_arg;

	nb_arg = 0;
	while (argv[nb_arg])
		nb_arg++;
	if (nb_arg < 3)
		return (werror(E_MISSING_ARG, "foreach", FALSE));
	if (argv[2][0] != '(' ||
		argv[nb_arg - 1][strlen(argv[nb_arg - 1]) - 1] != ')')
	{
		if (nb_arg < 4)
			return (werror(E_MISSING_ARG, "foreach", FALSE));
		else
			return (werror(E_WORD_PAR, "foreach", FALSE));
	}
	return (0);
}

static void	foreach_read_all(t_sh *sh, char **buff)
{
	char 	*line;

	*buff = "";
	line = NULL;
	if (isatty(0))
		write(1, "foreach? ", 9);
	while (get_input(sh, &line))
	{
		if (strstr(line, "end"))
			break;
		asprintf(buff, "%s%s \n", *buff, line);
		if (isatty(0))
			write(1, "foreach? ", 9);
	}
}

static void foreach_clean(char *buff)
{
	int 	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			buff[i] = ';';
		i++;
	}
}

static char **set_list(char **argv)
{
	int 	nb_arg;
	int 	i;
	int 	j;
	char 	**list;

	nb_arg = 2;
	while (argv[nb_arg])
		nb_arg++;
	if (!(list = malloc(sizeof(char *) * (nb_arg + 1))))
		return (NULL);
	i = 2;
	j = 0;
	while (i < nb_arg)
	{
		if (i == 2)
			list[j] = strdup(argv[i] + 1);
		else if (i == nb_arg - 1)
			list[j] = strndup(argv[i], strlen(argv[i]) - 1);
		else
			list[j] = strdup(argv[i]);
		i++;
		j++;
	}
	list[j] = NULL;
	return (list);
}

int 		builtin_foreach(t_sh *sh, char **argv)
{
	char	*buff;
	char 	**list;
	char 	*var[3];

	buff = "";
	if (foreach_error(argv))
		return (1);
	foreach_read_all(sh, &buff);
	foreach_clean(buff);
	if (!(list = set_list(argv)))
	{
		werror(E_MALLOC_FAIL, "foreach", FALSE);
		return (1);
	}
	asprintf(&var[0], "set");
	var[2] = NULL;
	while (*list)
	{
		asprintf(&var[1], "%s=%s", argv[1], *list);
		builtin_set(sh, var);
		sh_action(sh, buff);
		list++;
	}
	return (0);
}
