/*
** error.c for bistro-matic in /home/arthur/Documents/Piscine/Projets/CPool_bistro-matic/src/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Thu Oct 27 16:29:19 2016 Arthur Chaloin
** Last update Sun May 21 18:38:09 2017 Arthur Chaloin
*/
#include "bistro-matic.h"
#include "my.h"

static int	check_base(char *base)
{
  int		index;
  int		index2;

  index = 0;
  index2 = 0;
  if (my_strlen(base) < 2)
    return (EXIT_FAILURE);
  while (base[index])
    {
      while (base[index2])
	{
	  if (base[index] == base[index2] && index != index2)
	    return (EXIT_FAILURE);
	  index2 += 1;
	}
      index2 = 0;
      index += 1;
    }
  return (EXIT_SUCCESS);
}

static int	check_ops(char *ops, int nb_ops)
{
  int		index;
  int		index2;

  index = 0;
  index2 = 0;
  if (my_strlen(ops) != nb_ops)
    return (EXIT_FAILURE);
  while (ops[index])
    {
      while (ops[index2])
      	{
      	  if (ops[index] == ops[index2] && index != index2)
      	    return (EXIT_FAILURE);
      	  index2 += 1;
      	}
      index2 = 0;
      index += 1;
    }
  return (EXIT_SUCCESS);
}

int	check_base_ops_diff(char *base, char *ops)
{
  int	index;

  index = 0;
  while (base[index])
    {
      if (my_strstr(ops, my_strndup(base + index, 1)))
	return (EXIT_FAILURE);
      index += 1;
    }
  return (EXIT_SUCCESS);
}

int	verify(int ac, char **av, int nb_ops)
{
  if (ac != 0 && ac != 4)
    {
      write(2, "Usage : ", 9);
      write(2, av[0], my_strlen(av[0]));
      write(2, " base ops(+-*/%) exp_len\n", 26);
      return (EXIT_FAILURE);
    }
  if (check_base(av[1]) ||
      check_ops(av[2], nb_ops) ||
      my_getnbr(av[3]) < 1 ||
      check_base_ops_diff(av[1], av[2]))
    exit_error(SYNTAX_ERR);
  return (EXIT_SUCCESS);
}

void	exit_error(int error)
{
  if (error == SYNTAX_ERR)
    write(2, SYNTAX_ERROR_MSG, 12);
  else
    write(2, ERROR_MSG, 5);
  exit (EXIT_ERROR);
}
