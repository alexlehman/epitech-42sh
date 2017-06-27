/*
** signal.c for 42sh in /Users/arthur/Documents/Dev/Epitech/PSU/PSU_2016_42sh/src/init/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Sun May 21 16:48:14 2017 Arthur Chaloin
** Last update Sun May 21 22:59:26 2017 Arthur Chaloin
*/
#include <stdlib.h>
#include "error.h"
#include "my.h"

void	sigsegv_handler(__attribute__((unused))int signum)
{
  werror("Fatal error.", "42sh", false);
  end_gc();
  exit(1);
}
