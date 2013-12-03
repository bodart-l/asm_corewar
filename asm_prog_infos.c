/*
** asm_prog_infos.c for asm_prog_infos in /home/bodart/projets/Tek1/corewar/asm
** 
** Made by louis bodart
** Login   <bodart_l@epitech.net>
** 
** Started on Tue Mar 26 15:00:25 2013 louis bodart
** Last update Sun Mar 31 12:24:32 2013 BODART Louis
*/

#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"asm.h"
#include	"get_next_line.h"
#include	"op.h"
#include	"lib/lib.h"

void    	check_prog_infos(t_infos *infos)
{
  if (!infos->prog_name || my_strlen(infos->prog_name) > PROG_NAME_LENGTH)
    {
      my_printf(NAME_PROBLEM);
      exit(EXIT_FAILURE);
    }
  if (!infos->comment || my_strlen(infos->comment) > COMMENT_LENGTH)
    {
      my_printf(COMMENT_PROBLEM);
      exit(EXIT_FAILURE);
    }
}

static char    	*remove_quotes(char *str, int line_nbr)
{
  char		*new_str;
  int		i;
  int		j;

  i = 1;
  j = 0;
  if ((my_count_char(str, '"') != 2) ||
      (str[0] != '"' || str[my_strlen(str) - 1] != '"'))
    {
      my_printf(SYNTAX_ERROR, line_nbr);
      exit(EXIT_FAILURE);
    }
  new_str = my_malloc(sizeof(char) * (my_strlen(str) + 1));
  new_str = my_memset(new_str, 0, (my_strlen(str) + 1));
  while (i < my_strlen(str) - 1)
    new_str[j++] = str[i++];
  return (new_str);
}

static void    	put_in_infos(t_infos *infos, char **tab, int line_nbr)
{
  char		*value;

  value = remove_quotes(tab[1], line_nbr);
  if (!my_strcmp(NAME_CMD_STRING, tab[0]))
    infos->prog_name = value;
  else if (!my_strcmp(COMMENT_CMD_STRING, tab[0]))
    infos->comment = value;
  else
    {
      my_printf(UNKNOWN_CMD_STR, line_nbr);
      exit(EXIT_FAILURE);
    }
}

void		asm_prog_infos(t_infos *infos, char *line, int line_nbr)
{
  int		i;
  char		**tab;
  char		*element;
  char		*tmp;

  i = 1;
  element = my_epur_str(line);
  tab = my_explode(element, ' ');
  if (!tab[1])
    {
      my_printf(SYNTAX_ERROR, line_nbr);
      exit(EXIT_FAILURE);
    }
  tmp = tab[i++];
  while (tab[i])
    {
      tmp = my_strcat(tmp, " ");
      tmp = my_strcat(tmp, tab[i++]);
    }
  tab[1] = tmp;
  put_in_infos(infos, tab, line_nbr);
}
