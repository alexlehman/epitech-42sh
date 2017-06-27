/*
** core.c for 42sh in /Users/arthur/Dev/B2/PSU/PSU_2016_42sh/src/core/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Sat Apr 22 23:07:33 2017 Arthur Chaloin
** Last update Sun May 21 21:40:52 2017 Arthur Chaloin
*/
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include "sh.h"
#include "command.h"
#include "history.h"
#include "input.h"
#include "calc.h"
#include "my.h"

void		prompt(int ret)
{
  static int	ret_save = 0;
  char		buffer[1024];

  if (ret == -1)
    ret = ret_save;
  else
    ret_save = ret;
  getcwd(buffer, 1024);
  printf("(%d) \033[4m%s\033[0m:\033[1m%c%s\033[0m> ", ret,
	 getenv("HOST") ? getenv("HOST") : "host",
	 (!strncmp(buffer, getenv("HOME"), strlen(getenv("HOME")))) ? '~' : 0,
	 (!strncmp(buffer, getenv("HOME"), strlen(getenv("HOME")))) ?
	 (char *)buffer + strlen(getenv("HOME")) : buffer);
  fflush(stdout);
}

int		sh_action(t_sh *sh, char *input)
{
  int		count;
  int		ret;
  t_command	command;

  if (apply_env(&input))
    return (1);
  count = -1;
  while (++count < 4)
    {
      if (strncmp(input, "alias", 5))
	apply_alias(sh, &input);
    }
  if (apply_math(&input))
    return (1);
  globbing(&input);
  if ((ret = command_parse(sh, &command, input)))
    return ((ret == 1) ? 1 : 0);
  if (command.start)
    {
      GC_USE(0);
      ret = command_execute(sh, &command);
    }
  else
    ret = 0;
  return (ret);
}

int		sh_core(t_sh *sh)
{
  int		ret;
  char		*input;

  ret = 0;
  input = NULL;
  signal(SIGINT, SIG_IGN);
  if (isatty(fileno(stdin)))
    prompt(ret);
  while (get_input(sh, &input))
    {
      ret = sh_action(sh, input);
      if (sh->ret != -1)
	{
	  if (!ret)
	    {
	      ret = sh->ret;
	      sh->ret = -1;
	    }
	}
      if (isatty(fileno(stdin)))
	prompt(ret);
    }
  end_gc();
  return (ret);
}
