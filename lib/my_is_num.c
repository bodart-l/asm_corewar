/*
** my_is_num.c for my_is_num in /home/bodart/projets/Tek1/corewar/asm
** 
** Made by louis bodart
** Login   <bodart_l@epitech.net>
** 
** Started on Fri Mar 29 15:31:47 2013 louis bodart
** Last update Sun Mar 31 21:37:12 2013 BODART Louis
*/

#include	<stdlib.h>
#include	"asm.h"

void		my_is_num(char *str, int start, int line)
{
  int		i;

  i = start;
  if (str[i] && str[i] == '-')
    i++;
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9')
	{
	  my_printf(SYNTAX_ERROR, line);
	  exit(EXIT_FAILURE);
	}
      i++;
    }
}
