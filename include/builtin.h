/*
** builtin.h for mysh in /home/arthur/B2/PSU/PSU_2016_minishell2/include/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Tue Mar 21 15:31:11 2017 Arthur Chaloin
** Last update Sun May 21 23:38:12 2017 Thomas ARBONA
*/

#ifndef BUILTIN_H_
# define BUILTIN_H_

# include "sh.h"

typedef struct	s_builtin
{
  char		*name;
  int		(*func)(t_sh *, char **);
}		t_builtin;

typedef struct	s_if
{
  char		*cond;
  char		*body;
}		t_if;

# include "my.h"

t_if		*if_new(char *cond, char *body);
void		if_exec(t_sh *sh, t_list *ifs);
void		if_goto_nextword(char *buff, int *cursor);
int		if_read_full(t_sh *sh, char **buff);
int		if_getbody_oneline(char **body, char **argv,
				   int *index, int *cursor);
int		if_getcond_oneline(char **cond, char **argv,
				   int *index, int *cursor);
int		if_getcond(char **cond, char *buff, int *cursor);
int		if_parse(t_list *ifs, char *buff);

int		builtin_cd(t_sh *sh, char **argv);
int		builtin_echo(t_sh *sh, char **argv);
int		builtin_alias(t_sh *sh, char **argv);
int		builtin_source(t_sh *sh, char **argv);
int		builtin_env(t_sh *sh, char **argv);
int		builtin_setenv(t_sh *sh, char **argv);
int		builtin_unsetenv(t_sh *sh, char **argv);
int		builtin_where(t_sh *sh, char **argv);
int		builtin_which(t_sh *sh, char **argv);
int		builtin_source(t_sh *sh, char **argv);
int		builtin_exit(t_sh *sh, char **argv);
int		builtin_if(t_sh *sh, char **argv);
int		builtin_while(t_sh *sh, char **argv);
int		builtin_read(t_sh *sh, char **argv);
int		builtin_set(t_sh *sh, char **argv);
int		builtin_unset(t_sh *sh, char **argv);
int		builtin_repeat(t_sh *sh, char **argv);
int 	builtin_foreach(t_sh *sh, char **argv);

extern t_builtin	builtins[];

#endif /* !BUILTIN_H_ */
