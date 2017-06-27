/*
** globing.c for 42sh in /home/julien/dev/psu/psu-b2/42sh/globetest/
**
** Made by julien JOURDAN
** Login   <julien.jourdan@epitech.eu>
**
** Started on  Wed May 17 17:16:18 2017 julien JOURDAN
** Last update Jan May 21 18:01:37 2017 JULIEN JOURDAN
*/

#include <stdlib.h>
#include <glob.h>
#include <string.h>
#include "error.h"

static int      glob_len(glob_t glob_results)
{
    unsigned   	i;
    int		count;

    i = 0;
    count = 0;
    while (i < glob_results.gl_pathc)
    {
        count += strlen(glob_results.gl_pathv[i]) + 1;
        i++;
    }
    return (count);
}

static char     *all_input(char **input, int offset, char *gfile)
{
    int     	i;

    i = offset;
    while ((*input)[i] && (*input)[i] != ' ' && (*input)[i] != ';' &&
    (*input)[i] != '|' && (*input)[i] != '>' && (*input)[i] != '<')
        i++;
    strcat(gfile, (*input) + i);
    return (gfile);
}

static char     *get_word(char *s)
{
    char    	*tmp;
    int     	i;

    i = 0;
    while (s[i] && s[i] != ' ' && s[i] != ';' && s[i] != '|'
    && s[i] != '>' && s[i] != '<')
        i++;
    tmp = strndup(s, i);
    tmp[i] = 0;
    return (tmp);
}

static void			test_word(char **input, int offset)
{
    u_int32_t       i;
    u_int32_t       count;
    glob_t          glob_results;
    char            *gfile;

    i = count = 0;
    if (glob(get_word(*(input) + offset), GLOB_TILDE, 0, &glob_results) == 0)
    {
        count = glob_len(glob_results);
        if (!(gfile = malloc(sizeof(char) * (count + strlen(*input)))))
            werror(E_MALLOC_FAIL, "globbing", true);
        gfile = strncpy(gfile, *input, offset);
        gfile[offset] = 0;
        i = 0;
        while (i < glob_results.gl_pathc)
        {
            strcat(gfile, glob_results.gl_pathv[i]);
            if (glob_results.gl_pathc - i > 1)
                strcat(gfile, " ");
            i++;
        }
        globfree(&glob_results);
        *input = all_input(input, offset, gfile);
    }
}

void    globbing(char **input)
{
    int i;

    i = 0;
    while ((*input)[i])
    {
        while ((*input)[i] == ' ')
            i++;
        if ((*input)[i] != ' ' && (*input)[i] != '|' && (*input)[i] != '<' &&
        (*input)[i] != '>' && (*input)[i] != ';' && i > 0 &&
        ((*input)[i - 1] == ' ' || (*input)[i - 1] == '|' ||
        (*input)[i - 1] == '<' || (*input)[i - 1] == '>' ||
        (*input)[i - 1] == ';'))
            test_word(input, i);
        i++;
    }
}
