/*
** error.h for 42sh in /Users/arthur/Dev/B2/PSU/PSU_2016_42sh/include/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Sat Apr 22 22:13:41 2017 Arthur Chaloin
** Last update Sun May 21 18:49:25 2017 Antoine Briaux
*/

#ifndef ERROR_H_
# define ERROR_H_

# include <stdbool.h>

#ifndef E_INIT_FAIL
# define E_INIT_FAIL	"Shell init failed."
#endif

#ifndef E_MALLOC_FAIL
# define E_MALLOC_FAIL	"Malloc failed."
#endif

#ifndef E_PIPE_FAIL
# define E_PIPE_FAIL	"Can't make pipe."
#endif

#ifndef E_NOT_FOUND
# define E_NOT_FOUND	"No such file or directory."
#endif

#ifndef E_UNKNOWN_CMD
# define E_UNKNOWN_CMD	"Command not found."
#endif

#ifndef E_NOT_DIR
# define E_NOT_DIR	"Not a directory."
#endif

#ifndef E_BAD_MOD
# define E_BAD_MOD	"Permission denied."
#endif

#ifndef E_BAD_BEGIN
# define E_BAD_BEGIN	"Variable name must begin with a letter."
#endif

#ifndef E_BAD_NAME
# define E_BAD_NAME 	"Variable name must contain alphanumeric characters."
#endif

#ifndef E_MISSING_ARG
# define E_MISSING_ARG	"Too few arguments."
#endif

#ifndef E_BAD_PIPE
# define E_BAD_PIPE	"Invalid null command."
#endif

#ifndef E_BAD_REDIR
# define E_BAD_REDIR	"Missing name for redirect."
#endif

#ifndef E_AMBIGU_IN
# define E_AMBIGU_IN	"Ambiguous input redirect."
#endif

#ifndef E_AMBIGU_OUT
# define E_AMBIGU_OUT	"Ambiguous output redirect."
#endif

#ifndef E_BADLY_NB
# define E_BADLY_NB	"Badly formed number."
#endif

#ifndef E_WORD_PAR
# define E_WORD_PAR "Words not parenthesized."
#endif

int	werror(const char *error, char *context, bool fatal);
void	werror_signal(int signal, int core_dump);

#endif /* !ERROR_H_ */
