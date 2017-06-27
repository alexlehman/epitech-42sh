/*
** my.h for libmy in /home/arbona/CPool/CPool_Day09
**
** Made by Thomas Arbona
** Login   <arbona@epitech.net>
**
** Started on  Thu Oct 13 09:22:28 2016 Thomas Arbona
** Last update Sun May 21 18:42:38 2017 Arthur Chaloin
*/

#ifndef BASICS_H_
# define BASICS_H_

int	my_str_contain(const char *str, char to_find);
char	*convert_base(char *, char *, char *);
int	my_find_prime_sup(int);
int	my_getnbr_base(char *, char *);
int	my_getnbr(char *);
int	my_isneg(int);
int	my_is_prime(int);
int	my_power_rec(int, int);
void	my_putchar(char);
int	my_putnbr_base(int, char *);
int	my_put_nbr(int);
int	my_putstr(char *);
char	*my_revstr(char *);
int	my_showmem(char *, int);
int	my_showstr(char *);
int	my_show_wordtab(char **);
void	my_sort_int_tab(int *, int);
int	my_square_root(int);
char	*my_strcapitalize(char *);
char	*my_strcat(char *, char *);
int	my_strcmp(char *, char *);
char	*my_strcpy(char *, char *);
char	*my_strdup(char *);
char	*my_strndup(char *, int);
int	my_str_isalpha(char *);
int	my_str_islower(char *);
int	my_str_isnum(char *);
int	my_str_isprintable(char *);
int	my_str_isupper(char *);
int	my_strlen(char *);
char	*my_strlowcase(char *);
char	*my_strncat(char *, char *, int);
int	my_strncmp(char *, char *, int);
char	*my_strncpy(char *, char *, int);
char	*my_strstr(char *, char *);
char	**my_str_to_wordtab(char *, char *);
char	*my_strupcase(char *);
int	my_swap(int *, int *);
int	my_swapchar(char **, int, int);
int	my_swapstr(char **, char **);
int	my_find_in_wordtab(char **, char *);
void	my_memset(char *, int, char);
int	my_tablen(char **);
int	my_replace_char(char *, char, char);
char	*my_str_replace(char *, int, int, char *);
char	*my_int_to_str(int);
char	*my_int_to_base(int, char *);

#endif
