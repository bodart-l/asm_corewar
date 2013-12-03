/*
** my_strcut.c for my_strcut in /home/bodart/projets/Tek1/minishell1
** 
** Made by louis bodart
** Login   <bodart_l@epitech.net>
** 
** Started on Fri Dec 14 12:21:15 2012 louis bodart
** Last update Mon Dec 31 16:04:39 2012 BODART Louis
*/

#include	<stdlib.h>
#include	"lib.h"

char		*my_strcut(char *str, int pos)
{
  char		*new_str;
  int		i;

  i = 0;
  new_str = my_malloc(sizeof(char) * (my_strlen(str) + 1));
  new_str = my_memset(new_str, 0, (my_strlen(str) + 1));
  if (new_str == NULL)
    exit(-1);
  while (str[pos] != '\0' && pos < my_strlen(str))
    {
      new_str[i] = str[pos];
      new_str[i + 1] = '\0';
      i++;
      pos++;
    }
  return (new_str);
}
