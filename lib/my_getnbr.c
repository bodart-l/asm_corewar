/*
** my_getnbr.c for my_getnbr in /home/bodart_l//afslocal/rendu/libv2.0
** 
** Made by louis bodart
** Login   <bodart_l@epitech.net>
** 
** Started on  Wed Oct 17 15:15:22 2012 louis bodart
** Last update Mon Dec 31 15:59:17 2012 BODART Louis
*/

#include	"lib.h"

static	int	getnbr_op(int multiple, int j, char *str)
{
  int		result;

  result = 0;
  while (multiple >= 1)
    {
      result = result + ((str[j] - 48) * multiple);
      multiple /= 10;
      j++;
    }
  return (result);
}

static	int	getnbr_multiple(int i, char *str)
{
  int	multiple;

  multiple = 1;
  while ((i + 1) < my_strlen(str))
    {
      multiple *= 10;
      i++;
    }
  return (multiple);
}

int	my_getnbr(char *str)
{
  int	i;
  int	j;
  int	minus;

  i = 0;
  minus = 0;
  while (str[i] == 45 || str[i] == 43)
    {
      if (str[i] == 45)
	minus++;
      i++;
    }
  while (str[i] == 48 && str[i] != '\0')
    i++;
  if (str[i] == '\0')
    i--;
  j = i;
  if ((minus % 2) == 0)
    return (getnbr_op(getnbr_multiple(i, str), j, str));
  else
    return (getnbr_op(getnbr_multiple(i, str), j, str) * (-1));
}
