/*
** transposition.c for transposition in /home/onehandedpenguin/CPool_bistro-matic/bonus/src/func/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Sat Nov  5 12:07:10 2016 Paul Laffitte
** Last update Sat Nov  5 13:23:28 2016 Paul Laffitte
*/
#include "my.h"
#include "bistro-matic.h"
#include "bonus.h"

char	*transposition(char **argv)
{
  return (my_add(my_add(infin_opposite(argv), argv[1]), argv[2]));
}
