/*
** my_strdup.c for my_strdup in /home/bodart_l//afslocal/rendu/piscine/Jour_08/ex_01
** 
** Made by louis bodart
** Login   <bodart_l@epitech.net>
** 
** Started on  Thu Oct 11 10:41:16 2012 louis bodart
** Last update Mon Dec 31 16:05:03 2012 BODART Louis
*/

#include	<stdlib.h>
#include	"lib.h"

char		*my_strdup(char *str)
{
  int		i;
  int		size;
  char		*newstr;

  size = my_strlen(str) + 1;
  newstr = my_malloc(sizeof(char) * size);
  newstr = my_memset(newstr, 0, size);
  i = 0;
  while (str[i] != '\0')
    {
      newstr[i] = str[i];
      newstr[i + 1] = '\0';
      i++;
    }
  return (newstr);
}
