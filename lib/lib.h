/*
** lib.h for lib in /home/bodart/projets/SRC/lib
** 
** Made by louis bodart
** Login   <bodart_l@epitech.net>
** 
** Started on Mon Dec 31 15:57:13 2012 louis bodart
// Last update Tue Jan  1 14:59:28 2013 BODART Louis
*/

#ifndef LIB_H_
# define LIB_H_

#include	<stdlib.h>

int	my_count_char(char *, int);
char	*my_epur_str(char *);
char	**my_explode(char *, int);
int	my_getnbr(char *);
void	*my_malloc(size_t);
void	*my_memset(char *, int, int);
int	my_printf(const char *, ...);
void	my_put_nbr(int);
void	my_putchar(char);
void	my_putstr(char *);
char	*my_revstr(char *);
char	*my_strcat(char *, char *);
int	my_strcmp(char *, char *);
char	*my_strcut(char *, int);
char	*my_strdup(char *);
int	my_strlen(char *);

#endif /* !LIB_H_ */
