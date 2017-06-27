/*
** my_parse_file.c for libmy in /home/onehandedpenguin/Dev/mylib/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Tue Dec  6 23:23:29 2016 Paul Laffitte
** Last update Wed Dec 21 01:43:15 2016 Paul Laffitte
*/

#include "my/containers/my_list.h"
#include "my/utils/files.h"
#include "my/utils/errors.h"

void		**my_parse_file(int fd, t_line_parser *line_parser)
{
  t_list	*list;
  char		*line;
  void		*parsed_line;

  if ((list = create_list(LINKED_LIST)) == ERROR_NULL)
    return (ERROR_NULL);
  while ((line = my_getnextline(fd)))
    {
      parsed_line = line_parser(line);
      if (push_back(list, parsed_line) == ERROR_84)
	return (ERROR_NULL);
    }
  return (list_to_tab(list));
}
