/*
** my_revstr.c for my_revstr in /home/bodart_l//afslocal/rendu/piscine/Jour_06/ex_03
** 
** Made by louis bodart
** Login   <bodart_l@epitech.net>
** 
** Started on  Mon Oct  8 12:12:00 2012 louis bodart
** Last update Tue Jan  1 14:59:46 2013 BODART Louis
*/

char		*my_revstr(char *str)
{
  int		i;
  int		str_len;
  int		temp;

  i = 0;
  str_len = 0;
  while (str[str_len] != '\0')
    str_len++;
  while (i < str_len)
    {
      temp = str[i];
      str[i] = str[str_len - 1];
      str[str_len - 1] = temp;
      i++;
      str_len--;
    }
  return (str);
}
