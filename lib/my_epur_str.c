/*
** proto.c for proto in /home/bodart/projets/Tek1/LabC
** 
** Made by louis bodart
** Login   <bodart_l@epitech.net>
** 
** Started on Fri Mar  8 21:47:53 2013 louis bodart
** Last update Mon Mar 18 17:28:49 2013 BODART Louis
*/

#include	"lib.h"

int		words_after(char *str, int pos)
{
  while (str[pos] && str[pos] < 33)
    pos++;
  if (!str[pos])
    return (0);
  return (1);
}

int		remove_first_spaces(char *str)
{
  int		i;

  i = 0;
  while (str[i] && str[i] < 33)
    i++;
  return (i);
}

char		*my_epur_str(char *str)
{
  int		i;
  int		j;
  char		*new_str;
  int		space;

  j = 0;
  i = remove_first_spaces(str);
  new_str = my_malloc(sizeof(char) * (my_strlen(str) + 1));
  new_str = my_memset(new_str, 0, (my_strlen(str) + 1));
  space = 0;
  while (str[i])
    {
      if (str[i] < 33)
	while (str[i + 1] && str[i + 1] < 33)
	  i++;
      if (words_after(str, i))
	if (str[i] > 32 || str[i] == ' ')
	  new_str[j] = str[i];
	else
	  new_str[j] = ' ';
      j++;
      if (str[i])
	i++;
    }
  return (new_str);
}
