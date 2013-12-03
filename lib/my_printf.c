/*
** main.c for my_printf in /home/bodart_l/projets/printf
** 
** Made by BODART Louis
** Login   <bodart_l@epitech.net>
** 
** Started on  Mon Nov 12 09:22:37 2012 BODART Louis
** Last update Tue Jan  1 14:55:51 2013 BODART Louis
*/

#include	<stdarg.h>
#include	"lib.h"

void	my_putnbr_base(unsigned int, char *);

int	bonus_flag(const char *str, va_list ap, int *i)
{
  if (str[*i + 1] == '#' && (str[*i + 2] == 'd' || str[*i + 2] == 'i'))
    my_put_nbr(va_arg(ap, int));
  else if (str[*i + 1] == '+' && str[*i + 2] == 'd')
    my_put_nbr_aff_sign(va_arg(ap, int));
  else if (str[*i + 1] == '#' && str[*i + 2] == 'o')
    my_putnbr_base_zero(va_arg(ap, unsigned int), "01234567");
  else if (str[*i + 1] == '#' && str[*i + 2] == 'x')
    my_putnbr_base_zero(va_arg(ap, unsigned int), "0123456789abcdef");
  else
    return (1);
  *i += 1;
  return (0);
}

int	check_the_flag(const char *str, va_list ap, int *i)
{
  if (str[*i + 1] == 's')
    my_putstr(va_arg(ap, char *));
  else if (str[*i + 1] == 'S')
    pf_my_putstr_base(va_arg(ap, char *));
  else if (str[*i + 1] == 'c')
    my_putchar(va_arg(ap, int));
  else if (str[*i + 1] == 'u')
    my_put_nbr_ui(va_arg(ap, unsigned int));
  else if (str[*i + 1] == 'd' || str[*i + 1] == 'i')
    my_put_nbr(va_arg(ap, int));
  else if (str[*i + 1] == 'x')
    my_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
  else if (str[*i + 1] == 'b')
    my_putnbr_base(va_arg(ap, unsigned int), "01");
  else if (str[*i + 1] == 'X')
    my_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
  else if (str[*i + 1] == 'o')
    my_putnbr_base(va_arg(ap, unsigned int), "01234567");
  else if (str[*i + 1] == 'p')
    p_flag(va_arg(ap, unsigned int));
  else
    return (bonus_flag(str, ap, i));
  return (0);
}

int		my_printf(const char *str, ...)
{
  va_list	ap;
  int		i;

  i = 0;
  va_start(ap, str);
  while (str[i] != '\0')
    {
      if (str[i] == '%')
	{
	  if (check_the_flag(str, ap, &i) == 0)
	    i++;
	  else
	    {
	      my_putchar(str[i]);
	      if (str[i + 1] == '%')
		i++;
	      va_arg(ap, void);
	    }
	}
      else
	my_putchar(str[i]);
      i++;
    }
  va_end(ap);
  return (0);
}
