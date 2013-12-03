/*
** my_explode.c for my_explode in /home/bodart/projets/Tek1/minishell1v2/draft
** 
** Made by louis bodart
** Login   <bodart_l@epitech.net>
** 
** Started on Mon Dec 24 00:10:12 2012 louis bodart
** Last update Fri Mar  8 14:32:22 2013 BODART Louis
*/

#include	<stdlib.h>
#include	"lib.h"

static	int	count_words(char *str, int c)
{
  int		words;
  int		i;

  words = 0;
  i = 0;
  while (str[i] != '\0')
    if (str[i++] == c)
      words++;
  return (words + 1);
}

char		**my_explode(char *str, int c)
{
  char		**tab;
  int		cursor_tab;
  int		cursor_str;
  int		cursor_tab_str;

  tab = my_malloc(sizeof(char *) * (count_words(str, c) + 1));
  cursor_tab = 0;
  cursor_str = 0;
  while (cursor_tab < count_words(str, c))
    {
      cursor_tab_str = 0;
      tab[cursor_tab] = my_malloc(sizeof(char) * (my_strlen(str) + 1));
      while (str[cursor_str] != c && str[cursor_str] != '\0')
	{
	  tab[cursor_tab][cursor_tab_str] = str[cursor_str];
	  cursor_str++;
	  cursor_tab_str++;
	}
      tab[cursor_tab][cursor_tab_str] = '\0';
      if (str[cursor_str] != '\0')
	cursor_str++;
      cursor_tab++;
    }
  tab[cursor_tab] = NULL;
  return (tab);
}
