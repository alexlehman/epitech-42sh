/*
** read.c for 42sh in /home/arbona/tek1/PSU/PSU_2016_42sh
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Sun May 21 23:31:07 2017 Thomas ARBONA
** Last update Sun May 21 23:44:08 2017 Thomas ARBONA
*/
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "builtin.h"
#include "error.h"
#include "input.h"
#include "sh.h"

int	builtin_read(t_sh *sh, char **argv)
{
  char	*line;
  char	*set_val[3];

  if (argv[1] == NULL)
    return (werror("Miss variable name.", "read", 0));
  if (argv[2] != NULL)
    printf("%s", argv[1]);
  printf("?\n");
  get_input(sh, &line);
  set_val[0] = "set";
  asprintf(&set_val[1], "%s=%s", argv[2] != NULL ? argv[2] : argv[1], line);
  set_val[2] = NULL;
  builtin_set(sh, set_val);
  return (0);
}
