/*
** files.h for libmy in /home/onehandedpenguin/Dev/lib"my/include/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Wed Dec 21 00:20:12 2016 Paul Laffitte
** Last update Wed Dec 21 00:28:06 2016 Paul Laffitte
*/

#ifndef FILES_H_
# define FILES_H_
# define CORRUPTED_FILE "Corrupted file\n"
# define PARSING_FAILED "Parsing failed\n"

typedef void	*(t_line_parser)(char *line);

char	*my_getnextline(const int fd);
void	**my_parse_file(int fd, t_line_parser *line_parser);

#endif /* !FILES_H_ */
