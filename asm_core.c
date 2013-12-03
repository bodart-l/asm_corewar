/*
** asm_core.c for asm_core in /home/bodart/projets/Tek1/corewar/asm
** 
** Made by louis bodart
** Login   <bodart_l@epitech.net>
** 
** Started on Mon Mar 18 16:51:54 2013 louis bodart
** Last update Sat Mar 30 19:57:52 2013 BODART Louis
*/

#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"asm.h"
#include	"get_next_line.h"
#include	"op.h"
#include	"lib/lib.h"

static int	open_file(char *file)
{
  int		fd;

  if ((fd = open(file, O_RDONLY)) == -1)
    {
      my_printf(OPEN_FAILED, file);
      exit(EXIT_FAILURE);
    }
  return (fd);
}

static char    	*epur_instruction(char *instruct)
{
  char		**instruct_tab;
  char		*new_instruct;
  int		caracter;
  int		i;

  i = 0;
  caracter = 0;
  instruct_tab = my_explode(instruct, COMMENT_CHAR);
  new_instruct = my_epur_str(instruct_tab[0]);
  while (new_instruct[i])
    if (new_instruct[i++] > 32)
      caracter++;
  if (!caracter)
    return (NULL);
  i = 0;
  while (instruct_tab[i])
    free(instruct_tab[i++]);
  free(instruct_tab);
  return (new_instruct);
}

t_instruct     	*asm_core(t_instruct *list, t_infos *infos, char *file)
{
  int		fd;
  int		line_nbr;
  char		*new_instruct;
  char		*line;

  fd = open_file(file);
  line_nbr = 1;
  while (line = get_next_line(fd))
    {
      if (line[0] && line[0] != COMMENT_CHAR)
	{
	  new_instruct = epur_instruction(line);
	  if (new_instruct != NULL)
	    if (new_instruct[0] == NAME_CMD_STRING[0] ||
		new_instruct[0] == COMMENT_CMD_STRING[0])
	      asm_prog_infos(infos, new_instruct, line_nbr);
	    else
	      list = asm_line_parser(list, new_instruct, line_nbr);
	  free(new_instruct);
	}
      free(line);
      line_nbr++;
    }
  return (list);
}
