/*
** inhibitors.c for 42sh in /home/onehandedpenguin/Dev/PSU_2016/PSU_2016_42sh/src/utils/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Thu May 18 23:21:57 2017 Paul Laffitte
** Last update Sun May 21 17:10:59 2017 Arthur Chaloin
*/

#define _GNU_SOURCE
#include <string.h>
#include <stdio.h>
#include "utils.h"
#include "error.h"
#include "my.h"

static int	unmatched(char unmatched_inhibitor)
{
  char		error[16];

  sprintf(error, "Unmatched %c.", unmatched_inhibitor);
  werror(error, NULL, false);
  return (-1);
}

 static bool	is_escaped(t_inhibitor *inhib)
{
  int		i;
  int		count;

  if (inhib->index == 0)
    return (false);
  i = inhib->index - 1;
  if (inhib->str[i] != '\\')
    return (false);
  count = 0;
  while (i != -1 && inhib->str[i] == '\\')
    {
      ++count;
      --i;
    }
  return (count % 2 != 0 ? count : 0);
}

int		inhibite(t_inhibitor *inhib)
{
  int		start;
  int		id_inhibitor;
  char		end_inhibitor;

  start = inhib->index;
  if ((id_inhibitor = my_str_contain(inhib->inhibitors,
				     inhib->str[inhib->index])) == -1
      || is_escaped(inhib))
    return (0);
  if (id_inhibitor % 2 != 0)
    return (unmatched(inhib->inhibitors[id_inhibitor]));
  end_inhibitor = inhib->inhibitors[id_inhibitor + 1];
  ++inhib->index;
  while (inhib->str[inhib->index]
	 && (inhib->str[inhib->index] != end_inhibitor || is_escaped(inhib)))
    ++inhib->index;
  if (inhib->str[inhib->index] == '\0')
    return (unmatched(inhib->inhibitors[id_inhibitor]));
  return (inhib->index - start);
}

static int	remove_inhibitor(char *str, int position)
{
  int		i;
  int		count;

  count = 0;
  i = 0;
  while (position + i != 0 && str[position + --i] == '\\')
    {
      if (i % 2 == -1)
	++count;
    }
  my_strcpy(str + position - count, str + position + 1);
  return (count);
}

void		remove_inhibitors(t_inhibitor *inh)
{
  int		start;

  while (inh->str[inh->index])
    {
      if (my_str_contain(inh->inhibitors, inh->str[inh->index]) != -1)
	start = inh->index;
      else
	start = -1;
      inhibite(inh);
      if (start != -1 && start != inh->index)
	{
	  inh->index -= remove_inhibitor(inh->str, start);
	  inh->index -= remove_inhibitor(inh->str, inh->index - 1);
	}
      inh->index += inh->str[inh->index] == '\0' ? 0 : 1;
    }
}
