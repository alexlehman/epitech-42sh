/*
** utils.h for 42sh in /Users/arthur/Dev/B2/PSU/PSU_2016_42sh/include/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Sat Apr 22 22:55:27 2017 Arthur Chaloin
** Last update Sun May 21 21:55:42 2017 Paul Laffitte
*/

#ifndef UTILS_H_
# define UTILS_H_

#include <stdbool.h>

typedef struct	s_inhibitor
{
  char		*str;
  char		**seps;
  const char	*inhibitors;
  int		index;
}		t_inhibitor;

typedef struct	s_lexer
{
  bool		remove_inhib;
  int		tokens_count;
  char		**tokens;
  int		token_id;
}		t_lexer;

typedef int	(*t_lex_iterator)(t_inhibitor *inhib, t_lexer *lex,
		char **next_sep);

int	check_validity(char *str, char *inhibitors);
char	**lexer(char *str, char *seps[],
		const char *inhibitors, bool remove);
int	iterate_on_separators(t_inhibitor *inhib, t_lexer *lex,
			      t_lex_iterator iterator, int ret);
char	**strsplit(char *str, const char *sep);
int	my_str_contain(const char *str, char to_find);
void	set_read_mode(int mode);
char	*get_next_sep(t_inhibitor *inhib);
char	*get_sep(t_inhibitor *inhib);
bool	contain_only_seps(t_inhibitor *inhib);
void	remove_seps(t_inhibitor *inhib, t_lexer *lex);
void	remove_sep(t_inhibitor *inhib);
int	inhibite(t_inhibitor *inhib);
void	remove_inhibitors(t_inhibitor *inhib);

#endif /* !UTILS_H_ */
