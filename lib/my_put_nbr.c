/*
** my_put_nbr.c for my_put_nbr in /home/bodart_l//afslocal/rendu/libv2.0
** 
** Made by louis bodart
** Login   <bodart_l@epitech.net>
** 
** Started on  Wed Oct 17 14:39:38 2012 louis bodart
** Last update Mon Dec 31 16:01:31 2012 BODART Louis
*/

#include	"lib.h"

void		my_put_nbr(int nb)
{
  if (nb < 0)
    {
      nb = nb * (-1);
      if (nb > 0)
	my_putchar('-');
    }
  if (nb > 9 || nb < (-9))
    my_put_nbr(nb / 10);
  if ((nb % 10) >= 0)
    my_putchar((nb % 10) + 48);
  if ((nb % 10) < 0)
    my_putchar(((nb % 10) * (-1)) + 48);
}

void		my_put_nbr_aff_sign(int nb)
{
  if (nb < 0)
    {
      nb = nb * (-1);
      if (nb > 0)
	my_putchar('-');
    }
  else
    my_putchar('+');
  if (nb > 9 || nb < (-9))
    my_put_nbr(nb / 10);
  if ((nb % 10) >= 0)
    my_putchar((nb % 10) + 48);
  if ((nb % 10) < 0)
    my_putchar(((nb % 10) * (-1)) + 48);
}

void		my_put_nbr_ui(unsigned int nb)
{
  if (nb > 9)
    my_put_nbr_ui(nb / 10);
  my_putchar((nb % 10) + 48);
}
