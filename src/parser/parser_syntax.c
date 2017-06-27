/*
** parser_logic_error.c for 42sh in /Users/arthur/Documents/Dev/Epitech/PSU/PSU_2016_42sh/src/parser/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Sun May 21 22:07:07 2017 Arthur Chaloin
** Last update Sun May 21 22:22:56 2017 Arthur Chaloin
*/
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "command.h"
#include "parser.h"
#include "error.h"
#include "utils.h"

static void	epur_spaces(char **str)
{
  int		index;

  index = -1;
  while ((*str)[++index] && (*str)[index] == ' ');
  *str += index;
  while ((*str)[++index]);
  while ((*str)[--index] && (*str)[index] == ' ');
  (*str)[index + 1] = 0;
}

int	check_logic_syntax(t_node **node)
{
  epur_spaces((*node)->action);
  while ((*((*node)->action))[0])
    {
      if (!strncmp("&&", *((*node)->action), 2))
	*((*node)->action) += 2;
      else if ((*(*node)->action)[0] == ' ')
	*((*node)->action) += 1;
      else
	break;
    }
  if (!(*(*node)->action)[0])
    return (2);
  if (check_validity(*((*node)->action), INHIB) == EXIT_FAILURE)
    return (1);
  return (0);
}
