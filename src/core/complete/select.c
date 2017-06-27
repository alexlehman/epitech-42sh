/*
** select.c for mysh in /home/arthur/B2/PSU/PSU_2016_minishell2/bonus/src/core/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Fri Apr  7 14:23:03 2017 Arthur Chaloin
** Last update Sun May 21 22:00:55 2017 Arthur Chaloin
*/
#include <unistd.h>
#include <stdio.h>
#include "sh.h"
#include "complete.h"
#include "my.h"

static void	print_options(t_list *list, int cursor)
{
  int		index;
  t_list_elem	*tmp;

  index = 0;
  tmp = list->front;
  while (tmp)
    {
      if (index == cursor)
	printf("\033[47m\033[30m");
      printf("%s", (char *)tmp->data);
      if (index == cursor)
	printf("\033[37m\033[0m");
      printf("\n");
      index++;
      tmp = tmp->next;
    }
}

void		select_op(char **cmd, t_list *list)
{
  int		index;
  int		cursor;
  char		c;
  t_list_elem	*tmp;

  index = -1;
  cursor = c = 0;
  tmp = list->front;
  printf("\n");
  while (c != '\n')
    {
      print_options(list, cursor);
      read(0, &c, 1);
      if (c == '\t')
	{
	  tmp = (cursor < list->size - 1) ? tmp->next : list->front;
	  cursor = (cursor < list->size - 1) ? cursor + 1 : 0;
	}
      printf("\033[%dA", list->size);
    }
  while (++index < list->size)
    printf("                                                           \n");
  printf("\033[%dA", list->size + 1);
  prompt(-1);
  complete(cmd, (char *)tmp->data);
}
