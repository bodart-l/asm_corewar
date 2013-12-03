/*
** my_malloc.c for my_malloc in /home/bodart/projets/Tek1/minishell1v2/lib
** 
** Made by louis bodart
** Login   <bodart_l@epitech.net>
** 
** Started on Sun Dec 30 12:55:51 2012 louis bodart
** Last update Thu Mar 28 11:18:00 2013 BODART Louis
*/

#include	<stdlib.h>

void		*my_malloc(size_t size)
{
  void		*ptr;

  ptr = malloc(size);
  if (ptr == NULL)
    {
      my_printf("Can’t perform malloc\n");
      exit (-1);
    }
  return (ptr);
}
