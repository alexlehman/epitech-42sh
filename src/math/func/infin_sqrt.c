/*
** infin_sqrt.c for bistro-matic.c in /home/onehandedpenguin/CPool_bistro-matic/bonus/infin_sqrt/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Wed Nov  2 17:19:31 2016 Paul Laffitte
** Last update Sun Nov  6 15:28:14 2016 Paul Laffitte
*/
#include "my.h"
#include "bistro-matic.h"
#include "bonus.h"

static char	**init_argv(char *arg0, int arg1)
{
  char		**argv;

  if (!(argv = malloc(sizeof(char*) * 2)))
    exit_error(MALLOC_FAILED);
  argv[0] = arg0;
  argv[1] = my_int_to_base(arg1, g_arithmetic.base);
  return (argv);
}

static int	init_dichotomy(t_dichotomy *dicho)
{
  dicho->first_two_dgt_nb = convert_base(my_int_to_str(g_arithmetic.len_base),
	       "0123456789", g_arithmetic.base);
  dicho->two = "2";
  convert_base(dicho->two, "0123456789", g_arithmetic.base);
  return (0);
}

static int	calc_limits(t_dichotomy *dicho, int len_nb)
{
  char		**argv;

  argv = init_argv(dicho->first_two_dgt_nb, (len_nb - 1) / 2);
  dicho->low_limit = infin_pow(argv);
  free(argv);
  argv = init_argv(dicho->first_two_dgt_nb, (len_nb + 1) / 2);
  dicho->high_limit = infin_pow(argv);
  free(argv);
  return (0);
}

static int	calc_median(t_dichotomy *dicho, char *nb)
{
  dicho->median = my_div(my_add(dicho->low_limit, dicho->high_limit),
			 dicho->two);
  dicho->compare = max_nb(nb, infin_pow(init_argv(dicho->median, 2)));
  if (dicho->compare == 0)
    dicho->compare = 0 - max_nb(infin_pow(init_argv(dicho->median, 2)), nb);
  return (0);
}

char		*infin_sqrt(char **argv)
{
  t_dichotomy	dicho;
  int		len_nb;

  init_dichotomy(&dicho);
  if (argv[0][0] == g_arithmetic.ope_low[1])
    exit_error(SQRT_NEG);
  if (argv[0][0] == g_arithmetic.base[0] && argv[0][1] == '\0')
    return (argv[0]);
  len_nb = my_strlen(argv[0]);
  calc_limits(&dicho, len_nb);
  while (1)
    {
      calc_median(&dicho, argv[0]);
      if (my_strcmp(dicho.low_limit, dicho.median) == 0)
	return (dicho.low_limit);
      else if (dicho.compare == 0)
	return (dicho.median);
      else if (dicho.compare < 0)
	dicho.high_limit = dicho.median;
      else if (dicho.compare > 0)
	dicho.low_limit = dicho.median;
    }
  free(dicho.first_two_dgt_nb);
  return (NULL);
}
