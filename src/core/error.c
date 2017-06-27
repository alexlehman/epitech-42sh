/*
** error.c for 42sh in /Users/arthur/Dev/B2/PSU/PSU_2016_42sh/src/core/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Sat Apr 22 22:11:37 2017 Arthur Chaloin
** Last update Fri Apr 28 23:06:39 2017 Arthur Chaloin
*/
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include "error.h"

int	werror(const char *error, char *context, bool fatal)
{
  if (context)
    {
      if (fprintf(stderr, "%s: %s\n", context, error) < 0)
	exit(EXIT_FAILURE);
    }
  else
    {
      if (fprintf(stderr, "%s\n", error) < 0)
      	exit(EXIT_FAILURE);
    }
  if (fatal)
    exit(EXIT_FAILURE);
  return (EXIT_FAILURE);
}

void	werror_signal(int signal, int core_dump)
{
  if (signal == SIGABRT)
    fprintf(stderr, "Abort");
  if (signal == SIGINT)
    fprintf(stderr, "Interupted");
  if (signal == SIGSEGV)
    fprintf(stderr, "Segmentation fault");
  if (signal == SIGKILL)
    fprintf(stderr, "Killed");
  if (signal == SIGTERM)
    fprintf(stderr, "Terminated");
  if (signal == SIGFPE)
    fprintf(stderr, "Floating exception");
  if (core_dump)
    fprintf(stderr, " (core dumped)\n");
  else
    fprintf(stderr, "\n");
}
