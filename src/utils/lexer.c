/*
** lexer.c for 42sh in /home/onehandedpenguin/Dev/PSU_2016/PSU_2016_42sh/src/utils/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Thu May 18 13:52:29 2017 Paul Laffitte
** Last update Sun May 21 18:51:14 2017 Arthur Chaloin
*/

#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "my.h"

static int	count_tokens(t_inhibitor *inhib, t_lexer *lex,
			       char **next_sep)
{
  while ((inhib->str + inhib->index == *next_sep))
    {
      inhib->index += strlen(get_sep(inhib));
      *next_sep = get_next_sep(inhib);
    }
  if (inhib->str[inhib->index] != '\0')
    ++lex->tokens_count;
  return (0);
}

static int	get_next_token(t_inhibitor *inhib, t_lexer *lex,
			       char **next_sep)
{
  int		tmp;
  char		*sep_dup;

  sep_dup = strdup(get_sep(inhib));
  tmp = inhib->index;
  while ((inhib->str + inhib->index == *next_sep))
    {
      inhib->index += strlen(get_sep(inhib));
      *next_sep = get_next_sep(inhib);
    }
  if (inhib->str[inhib->index] != '\0')
    {
      lex->tokens[lex->token_id] = inhib->str + tmp;
      lex->tokens[lex->tokens_count + lex->token_id] = sep_dup;
      ++lex->token_id;
    }
  else
    free(sep_dup);
  return (0);
}

static void	tokens_cleanup(t_inhibitor *inhib, t_lexer *lex)
{
  int		i;
  t_inhibitor	tok_inhib;

  tok_inhib.seps = inhib->seps;
  tok_inhib.inhibitors = inhib->inhibitors;
  i = -1;
  while (lex->tokens[++i])
    {
      tok_inhib.str = lex->tokens[i];
      remove_seps(&tok_inhib, lex);
      tok_inhib.index = 0;
      if (lex->remove_inhib)
	remove_inhibitors(&tok_inhib);
      lex->tokens[i] = tok_inhib.str;
    }
}

static int	tokenize(t_inhibitor *inhib, t_lexer *lex)
{
  inhib->index = 0;
  lex->tokens[0] = inhib->str;
  lex->tokens[lex->tokens_count] = NULL;
  lex->tokens[lex->tokens_count * 2] = NULL;
  if (lex->tokens_count != 0)
    {
      lex->token_id = 1;
      while (lex->token_id < lex->tokens_count)
	{
	  if (iterate_on_separators(inhib, lex, get_next_token, 0) == -1)
	    return (-1);
	  ++lex->token_id;
	}
      tokens_cleanup(inhib, lex);
    }
  return (0);
}

char		**lexer(char *str, char *seps[], const char *inhibitors,
			bool remove_inhib)
{
  t_inhibitor	inhib;
  t_lexer	lex;

  if (str == NULL)
    return (NULL);
  inhib.str = str;
  inhib.seps = seps;
  inhib.inhibitors = inhibitors;
  inhib.index = 0;
  lex.remove_inhib = remove_inhib;
  lex.tokens_count = 1;
  if (contain_only_seps(&inhib))
    {
      if (!(lex.tokens = malloc(sizeof(char *) * 1)))
	return (NULL);
      lex.tokens[0] = NULL;
      return (lex.tokens);
    }
  if (iterate_on_separators(&inhib, &lex,
			    (t_lex_iterator)&count_tokens, 0) == -1
      || !(lex.tokens = malloc(sizeof(char *) * (lex.tokens_count * 2 + 1)))
      || tokenize(&inhib, &lex) == -1)
    return (NULL);
  return (lex.tokens);
}
