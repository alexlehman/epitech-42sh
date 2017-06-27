/*
** eval_func.h for bonus in /home/arbona/CPool/CPool_bistro-matic/bonus/include/eval_func/
**
** Made by Thomas Arbona
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Sat Nov  5 00:12:53 2016 Thomas Arbona
** Last update Sat Nov  5 18:18:28 2016 Arthur Chaloin
*/

#ifndef EVAL_FUNC_H_
# define EVAL_FUNC_H_

char		*eval_func(char *expr);
char		*exec_func(char *func);
char		*str_replace(char *str, int start, int end, char *nb);
char		**get_func_args(char *expr, int nb_args);

#endif /* !EVAL_FUNC_H_ */
