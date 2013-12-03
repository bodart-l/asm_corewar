/*
** my_count_char.c for my_count_char in /home/bodart/projets/Tek1/minishell1v2
** 
** Made by louis bodart
** Login   <bodart_l@epitech.net>
** 
** Started on Sun Dec 30 15:52:12 2012 louis bodart
** Last update Sun Dec 30 15:56:28 2012 BODART Louis
*/

int		my_count_char(char *str, int c)
{
  int		i;
  int		nbr;

  i = 0;
  nbr = 0;
  while (str[i] != '\0')
    if (str[i++] == c)
      nbr++;
  return (nbr);
}
