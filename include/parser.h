/*
** parser.h for mysh in /home/arthur/B2/PSU/PSU_2016_minishell2/include/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Tue Mar 21 15:00:19 2017 Arthur Chaloin
** Last update Sun May 21 22:09:18 2017 Arthur Chaloin
*/

#ifndef PARSER_H_
# define PARSER_H_

# include "command.h"

typedef struct	s_redir
{
  int		ltype;
  int		rtype;
  char		*left;
  char		*right;
  char		**command;
}		t_redir;

int	parser_command(t_command *command, char *raw_command);
int	parser_separators(t_command *command);
int	parser_pipes(t_node **node);
int	parser_logic(t_node **node);
int	parser_redirects(t_node **node);

int	check_syntax(char *command);
int	check_doubles(char *command);
int	check_syntax(char *command);
int	check_ambigues(t_node **node);
int	check_logic_syntax(t_node **node);

void	insert_node(t_node **actual, char *op, char **action, int side);

#endif /* !PARSER_H_ */
