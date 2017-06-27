/*
** answer.c for answer in /home/onehandedpenguin/CPool_bistro-matic/bonus/src/func/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Sat Nov  5 12:18:28 2016 Paul Laffitte
** Last update Sat Nov  5 12:49:09 2016 Paul Laffitte
*/
#include "my.h"
#include "bistro-matic.h"
#include "bonus.h"

char	*answer(char **argv)
{
  (void)argv;
  return (convert_base("42", "0123456789", g_arithmetic.base));
}
