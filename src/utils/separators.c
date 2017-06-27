/*
** separators.c for 42sh in /home/onehandedpenguin/Dev/PSU_2016/PSU_2016_42sh/src/utils/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Thu May 18 23:27:44 2017 Paul Laffitte
** Last update Sat May 20 19:36:03 2017 Paul Laffitte
*/

#include <string.h>
#include "utils.h"
#include "my.h"

char	*get_next_sep(t_inhibitor *inhib)
{
  int	i;
  char	*next_sep;
  char	*tmp;

  next_sep = NULL;
  i = 0;
  while (inhib->seps[i])
    {
      if (!next_sep)
	next_sep = strstr(inhib->str + inhib->index, inhib->seps[i]);
      if ((tmp = strstr(inhib->str + inhib->index, inhib->seps[i]))
	  && tmp < next_sep)
	next_sep = tmp;
      ++i;
    }
  return (next_sep);
}

char	*get_sep(t_inhibitor *inhib)
{
  int	i;

  i = 0;
  while (inhib->seps[i])
    {
      if (strstr(inhib->str + inhib->index, inhib->seps[i])
	  == inhib->str + inhib->index)
	return (inhib->seps[i]);
      ++i;
    }
  return (NULL);
}

bool	contain_only_seps(t_inhibitor *inhib)
{
  char	*next_sep;
  int	i;

  next_sep = NULL;
  i = 0;
  while ((inhib->str + i == next_sep))
    {
      i += strlen(get_sep(inhib));
      next_sep = get_next_sep(inhib);
    }
  return ((inhib->str[i] == '\0'));
}

void	remove_seps(t_inhibitor *inhib, t_lexer *lex)
{
  int	len_sep;
  char	*sep;

  if (inhib->str[0] == '\0')
    ++inhib->str;
  inhib->index = 0;
  while ((sep = get_sep(inhib)))
    {
      len_sep = strlen(sep);
      remove_sep(inhib);
      inhib->str += len_sep;
    }
  inhib->index = 0;
  iterate_on_separators(inhib, lex, (t_lex_iterator)&remove_sep, 0);
}

void	remove_sep(t_inhibitor *inhib)
{
  my_strcpy(inhib->str + inhib->index + 1,
	    inhib->str + inhib->index + strlen(get_sep(inhib)));
  inhib->str[inhib->index] = '\0';
}
