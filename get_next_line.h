/*
** get_next_line.h for get_next_line in /home/bodart/projets/Tek1/getnextline/v2
** 
** Made by louis bodart
** Login   <bodart_l@epitech.net>
** 
** Started on Fri Dec 14 16:47:53 2012 louis bodart
// Last update Sun Dec 23 23:09:24 2012 BODART Louis
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

#define MAX_READ	10000

typedef	struct	s_list
{
  char		caracter;
  struct s_list	*nxt;
}		t_list;

char	*get_next_line(const int);

#endif /* !GET_NEXT_LINE_H_ */
