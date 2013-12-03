/*
** test.c for test in /home/bodart_l/projets/printf
** 
** Made by BODART Louis
** Login   <bodart_l@epitech.net>
** 
** Started on  Tue Nov 13 13:46:08 2012 BODART Louis
** Last update Tue Jan  1 14:56:09 2013 BODART Louis
*/

#include	<stdlib.h>
#include	"lib.h"

int		malloc_help(unsigned int nbr, char *base)
{
  unsigned int	rest;
  unsigned int	i;

  i = 0;
  rest = nbr;
  while (rest != 0 && rest != 1)
    {
      rest = rest / my_strlen(base);
      i++;
    }
  return (i);
}

void		my_putnbr_base(unsigned int nbr, char *base)
{
  unsigned int	j;
  char		*tab;

  j = 0;
  tab = my_malloc(sizeof(char) * (malloc_help(nbr, base) + 1));
  while (nbr != 0 && nbr != 1)
    {
      tab[j] = base[nbr % my_strlen(base)];
      nbr = nbr / my_strlen(base);
      j++;
    }
  if (base[nbr] != base[0])
    tab[j] = base[nbr % my_strlen(base)];
  my_putstr(my_revstr(tab));
}

void		my_putnbr_base_zero(unsigned int nbr, char *base)
{
  unsigned int	j;
  char		*tab;

  j = 0;
  tab = my_malloc(sizeof(char) * (malloc_help(nbr, base) + 3));
  while (nbr != 0 && nbr != 1)
    {
      tab[j] = base[nbr % my_strlen(base)];
      nbr = nbr / my_strlen(base);
      j++;
    }
  if (base[nbr] != base[0])
    {
      tab[j] = base[nbr % my_strlen(base)];
      j++;
    }
  if (my_strlen(base) == 8)
    tab[j] = '0';
  else if (my_strlen(base) == 16)
    {
      tab[j] = 'x';
      tab[j + 1] = '0';
    }
  my_putstr(my_revstr(tab));
}

void	pf_other_char(int letter)
{
  int	i;
  int	j;
  int	tmp;

  i = 0;
  j = 0;
  tmp = letter;
  my_putchar('\\');
  while (tmp > 9)
    {
      tmp /= 10;
      i++;
    }
  while (j < (2 - i))
    {
      my_putchar('0');
      j++;
    }
  my_putnbr_base(letter, "01234567");
}

int	pf_my_putstr_base(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 32 || str[i] >= 127)
	pf_other_char(str[i]);
      else
	my_putchar(str[i]);
      i++;
    }
  return (0);
}
