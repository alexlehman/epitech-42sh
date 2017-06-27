/*
** lexer.h for eval_expr in /home/arthur/Documents/Piscine/CPool_evalexpr/include/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Thu Oct 27 14:46:32 2016 Arthur Chaloin
** Last update Mon Oct 31 11:26:16 2016 Thomas Arbona
*/

#ifndef LEXER_H_
# define LEXER_H_

typedef struct	s_cursors
{
  int		one;
  int		two;
}		t_cursors;

typedef struct	s_array_cursor
{
  int		cursor;
  char		**array;
}		t_array_cursor;

void	update_level(int *level, char cursor);
void	reset_lexer_cursors(t_cursors *cursors);
void	handle_block(char **str);
int	is_block(char *str);
int	is_sign_block(char *str);
void	normalize_sign(char **str);

#endif /* !LEXER_H_ */
