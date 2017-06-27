/*
** main.c for 42sh in /Users/arthur/Dev/B2/PSU/PSU_2016_42sh/src/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Sat Apr 22 22:04:15 2017 Arthur Chaloin
** Last update Sun May 21 23:00:52 2017 Arthur Chaloin
*/
#include <stdlib.h>
#include "sh.h"
#include "calc.h"
#include "error.h"
#include "my.h"

int	main(int ac, char **av, char **envp)
{
  t_sh	sh;

  if (!envp || !envp[0])
    {
      werror("No envp. Aborting.", "42sh", false);
      return (1);
    }
  init_gc(2);
  if (sh_init(&sh) != EXIT_SUCCESS)
    {
      werror(E_INIT_FAIL, NULL, false);
      return (EXIT_FAILURE);
    }
  if (ac > 1)
    return (sh_exec_file(&sh, av[1]));
  return (sh_core(&sh));
}
