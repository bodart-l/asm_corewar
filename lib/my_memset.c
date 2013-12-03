/*
** my_memset.c for my_memset in /home/bodart/projets/Tek1/minishell1v2/lib
** 
** Made by louis bodart
** Login   <bodart_l@epitech.net>
** 
** Started on Sun Dec 23 23:51:49 2012 louis bodart
** Last update Mon Dec 31 16:00:47 2012 BODART Louis
*/

void		*my_memset(char *ptr, int c, int nb)
{
  int		i;

  i = 0;
  while (i < nb)
    ptr[i++] = c;
  return (ptr);
}
