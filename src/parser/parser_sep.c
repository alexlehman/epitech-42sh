/*
** parser_sep.c for mysh in /home/arthur/B2/PSU/PSU_2016_minishell2/src/parser/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Wed Apr  5 19:43:00 2017 Arthur Chaloin
** Last update Sat May 20 21:10:00 2017 Arthur Chaloin
*/
#include <unistd.h>
#include <stdlib.h>
#include "command.h"
#include "parser.h"
#include "error.h"
#include "utils.h"

int		parser_separators(t_command *command)
{
  int		index;
  char		**tab;
  t_node	*actual;

  index = -1;
  tab = lexer(strdup(command->raw), (char *[]) {";", NULL}, "\"\"''", false);
  if (!tab)
    return (1);
  if (!tab[0])
    return (2);
  actual = command->start;
  while (tab[++index] && tab[index + 1])
    {
      insert_node(&actual, ";", NULL, 1);
      if (!command->start)
	command->start = actual;
      else
	actual = actual->right;
      insert_node(&actual, NULL, &tab[index], 0);
    }
  insert_node(&actual, NULL, &tab[index], 1);
  if (!command->start)
    command->start = actual;
  return (0);
}
