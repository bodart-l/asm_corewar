/*
** my_strlen.c for my_strlen in /home/bodart/projets/Tek1/myLs
** 
** Made by louis bodart
** Login   <bodart_l@epitech.net>
** 
** Started on Wed Nov 28 13:38:27 2012 louis bodart
** Last update Mon Dec 31 16:05:17 2012 BODART Louis
*/

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}
