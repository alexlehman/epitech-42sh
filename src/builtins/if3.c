/*
** if3.c for 42sh in /home/arbona/tek1/PSU/PSU_2016_42sh
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Sat May 20 19:36:46 2017 Thomas ARBONA
** Last update Sun May 21 23:08:23 2017 Arthur Chaloin
*/
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "sh.h"
#include "builtin.h"
#include "input.h"
#include "my.h"

int     if_getcond(char **cond, char *buff, int *cursor)
{
  int   start;
  int   index;
  int   depth;

  index = 0;
  depth = 0;
  start = 0;
  if_goto_nextword(buff, &start);
  while (buff[index] != 0)
    {
      if (buff[index] == '(' && depth == 0)
	start = index;
      if (buff[index] == ')' && depth == 1)
	{
	  *cond = strndup(buff + start + 1, index - start - 1);
	  *cursor = index + 1;
	  return (0);
	}
      depth += (buff[index] == '(') ? 1
	: (buff[index] == ')') ? -1 : 0;
      index += 1;
    }
  return (-1);
}

static int	if_parse2(t_list *ifs, char *buff, int start, int cursor)
{
  t_if		*curr_if;

  curr_if = (t_if*)ifs->back->data;
  while (buff[cursor] != 0)
    {
      if (strncmp(buff + cursor, "else", 4) == 0)
	{
	  if (curr_if->cond == NULL)
	    return (-1);
	  curr_if->body = strndup(buff + start, cursor - start);
	  push_back(ifs, if_new("", ""));
	  return (if_parse(ifs, buff + cursor + 4));
	}
      if (strncmp(buff + cursor, "endif", 5) == 0)
	{
	  curr_if->body = strndup(buff + start, cursor - start);
	  return (0);
	}
      if (buff[cursor] == '\n')
	buff[cursor] = ';';
      cursor += 1;
    }
  return (-1);
}

int     if_parse(t_list *ifs, char *buff)
{
  t_if  *curr_if;
  int   start;
  int   cursor;

  curr_if = (t_if*)ifs->back->data;
  cursor = 0;
  if_goto_nextword(buff, &cursor);
  curr_if->cond = NULL;
  if (strncmp(buff + cursor, "if", 2) == 0)
    {
      cursor = 2;
      if (if_getcond(&curr_if->cond, buff, &cursor) == -1)
	return (-1);
      if_goto_nextword(buff, &cursor);
      if (strncmp(buff + cursor, "then", 4) != 0)
	return (-1);
      cursor += 4;
      if_goto_nextword(buff, &cursor);
    }
  start = cursor;
  return (if_parse2(ifs, buff, start, cursor));
}

void            if_exec(t_sh *sh, t_list *ifs)
{
  t_list_elem   *curr;
  t_if          *curr_if;

  curr = ifs->front;
  while (curr != NULL)
    {
      curr_if = (t_if*)curr->data;
      if (curr_if->cond == NULL ||
	  (curr_if->cond[0] == '[' && sh_action(sh, curr_if->cond) == 0) ||
	  (curr_if->cond[0] != '[' && atoi(curr_if->cond)))
	{
	  sh_action(sh, curr_if->body);
	  return;
	}
      curr = curr->next;
    }
}
