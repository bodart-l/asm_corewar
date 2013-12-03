/*
** my_atoi.c for my_atoi in /home/bodart/projets/Tek1/verifsvn
** 
** Made by louis bodart
** Login   <bodart_l@epitech.net>
** 
** Started on Wed Feb  6 09:49:04 2013 louis bodart
** Last update Fri Mar 29 16:17:31 2013 BODART Louis
*/

int		is_nan(char *str)
{
  int		i;

  i = 0;
  if (str[i] && str[i] == '-')
    i++;
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9')
	return (1);
      i++;
    }
  return (0);
}

int		my_atoi(char *str)
{
  int		i;
  int		init;
  int		result;
  int		sign;
  int		size;

  init = 0;
  sign = 1;
  size = 1;
  result = 0;
  if (is_nan(str))
    return (0);
  if (str[0] == '-')
    {
      sign = -1;
      init = 1;
    }
  i = init;
  while (str[i++] != '\0')
    size *= 10;
  i = init;
  while ((size /= 10) >= 1)
    result += (str[i++] - 48) * size;
  return (result * sign);
}
