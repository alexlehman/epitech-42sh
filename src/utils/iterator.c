/*
** iterator.c for 42sh in /home/onehandedpenguin/Dev/PSU_2016/PSU_2016_42sh/src/utils/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Sun May 21 16:45:52 2017 Paul Laffitte
** Last update Sun May 21 22:12:31 2017 Paul Laffitte
*/

#include <stdlib.h>
#include <string.h>
#include "error.h"
#include "utils.h"

static int	check(t_inhibitor *inhib, char c, int *count)
{
  if (inhib->index == 0 || inhib->str[inhib->index - 1] != c)
    ++(*count);
  else if (inhib->index != 0)
    return (werror(E_BAD_PIPE, NULL, false));
  return (0);
}

int		check_validity(char *str, char *inhibitors)
{
  t_inhibitor	inhib;
  int		count;

  count = 0;
  inhib = (t_inhibitor){str, (char *[]){NULL}, inhibitors, -1};
  while (str[++inhib.index])
    {
      if (inhibite(&inhib) == -1)
	return (EXIT_FAILURE);
      if (str[inhib.index] == '&')
	{
	  if (check(&inhib, '|', &count) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	}
      else if (str[inhib.index] == '|')
	{
	  if (check(&inhib, '&', &count) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	}
      else
	count = 0;
      if (count == 3)
	return (werror(E_BAD_PIPE, NULL, false));
    }
  return (0);
}

int		iterate_on_separators(t_inhibitor *inhib, t_lexer *lex,
				      t_lex_iterator iterator, int ret)
{
  int		tmp;
  char		*next_sep;
  char	*sep;

  next_sep = NULL;
  while (inhib->str[inhib->index] != '\0')
    {
      inhibite(inhib);
      if (inhib->str + inhib->index == next_sep
	  && !((sep = get_sep(inhib)) && strcmp(inhib->str, sep) == 0))
	{
	  if ((tmp = iterator(inhib, lex, &next_sep)) == -1)
	    return (-1);
	  continue;
	}
      else if (!next_sep || inhib->str + inhib->index > next_sep)
	next_sep = get_next_sep(inhib);
      if (inhib->str[inhib->index] != '\0')
	++inhib->index;
    }
  return (ret);
}
