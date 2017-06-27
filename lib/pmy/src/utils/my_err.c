/*
** my_err.c for libmy in /home/onehandedpenguin/Dev/mylib/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Mon Dec  5 18:49:41 2016 Paul Laffitte
** Last update Fri Apr 28 20:39:10 2017 Arthur Chaloin
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "my/utils/errors.h"

int	my_print_err(const char* err)
{
  return (write(2, err, strlen(err)));
}

void	my_exit(const char* err)
{
  fprintf(stderr, "%s\n", err);
  exit(ERROR_84);
}
