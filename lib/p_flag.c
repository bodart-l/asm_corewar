/*
** p_flag.c for p_flag in /home/bodart_l/projets/printf
** 
** Made by BODART Louis
** Login   <bodart_l@epitech.net>
** 
** Started on  Tue Nov 13 09:43:46 2012 BODART Louis
** Last update Sat Nov 17 09:55:07 2012 BODART Louis
*/

void	p_flag(unsigned int nb)
{
  if (nb)
    {
      my_putstr("0x");
      my_putnbr_base(nb, "0123456789abcdef");
    }
  else
    my_putstr("(nil)");
}
