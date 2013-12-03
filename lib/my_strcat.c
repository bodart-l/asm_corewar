/*
** my_strcat.c for my_strcat in /home/bodart/projets/Tek1/minishell1
** 
** Made by louis bodart
** Login   <bodart_l@epitech.net>
** 
** Started on Thu Dec 13 17:14:52 2012 louis bodart
** Last update Wed Mar 27 15:50:49 2013 BODART Louis
*/

#include	<stdlib.h>
#include	"lib.h"

char		*my_strcat(char *init, char *comp)
{
  char		*str;
  int		i;
  int		j;

  i = my_strlen(init);
  j = my_strlen(comp);
  str = my_malloc(sizeof(char) * (i + j + 2));
  str = my_memset(str, 0, (i + j + 2));
  i = 0;
  j = 0;
  while (init[i] != '\0')
    {
      str[i] = init[i];
      str[i + 1] = '\0';
      i++;
    }
  while (comp[j] != '\0')
    {
      str[i] = comp[j];
      str[i + 1] = '\0';
      i++;
      j++;
    }
  return (str);
}
