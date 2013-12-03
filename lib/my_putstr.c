/*
** my_putstr.c for my_putstr in /home/bodart/projets/SRC
** 
** Made by louis bodart
** Login   <bodart_l@epitech.net>
** 
** Started on Thu Nov 22 17:02:33 2012 louis bodart
** Last update Mon Dec 31 16:01:57 2012 BODART Louis
*/

#include	<unistd.h>
#include	<stdlib.h>

void		my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    exit(-1);
}

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    my_putchar(str[i++]);
}
