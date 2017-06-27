/*
** scripting.c for 42sh in /home/arbona/tek1/PSU/PSU_2016_42sh
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Fri May 19 23:45:46 2017 Thomas ARBONA
** Last update Sun May 21 23:08:25 2017 Arthur Chaloin
*/
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "sh.h"

int	sh_exec_file(t_sh *sh, char *filename)
{
  char	*action;

  asprintf(&action, "cat %s | ./42sh", filename);
  return (sh_action(sh, action));
}
