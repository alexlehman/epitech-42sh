/*
** sh.h for 42sh in /Users/arthur/Dev/B2/PSU/PSU_2016_42sh/include/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Sat Apr 22 22:04:39 2017 Arthur Chaloin
** Last update Sun May 21 23:07:26 2017 Arthur Chaloin
*/

#ifndef SH_H_
# define SH_H_

# include <stdbool.h>
# include "history.h"
# include "alias.h"
# include "my/containers/my_map.h"

#ifndef INHIB
# define INHIB "\"\"''"
#endif

typedef struct	s_fd
{
  int		in;
  int		out;
}		t_fd;

typedef struct	s_sh
{
  int		ret;
  char		**path;
  t_list	*alias;
  t_map		*bin;
  t_history	*history;
}		t_sh;

extern char **environ;

int	sh_init(t_sh *sh);
int	sh_core(t_sh *sh);
int	sh_action(t_sh *sh, char *input);
int	sh_execute(t_sh *sh, char **argv, t_fd fd);
int	sh_exec_file(t_sh *sh, char *filename);

void	prompt(int ret);

void    globbing(char **input);
void	apply_alias(t_sh *sh, char **command);
int	apply_env(char **command);

void	sigsegv_handler(int signum);

#endif /* !SH_H_ */
