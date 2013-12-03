/*
** asm_convert.c for asm_convert in /home/bodart/projets/Tek1/corewar/asm
** 
** Made by louis bodart
** Login   <bodart_l@epitech.net>
** 
** Started on Mon Mar 25 15:31:53 2013 louis bodart
** Last update Sat Mar 30 19:57:33 2013 BODART Louis
*/

#include	<stdlib.h>
#include	"asm.h"
#include	"op.h"

extern op_t	op_tab[];

int		encode_params(t_instruct *, t_instruct *, int *);

static int     	define_byte_coding(char **params)
{
  int		i;
  int		offset;
  int		byte_code;

  i = 0;
  offset = 0;
  byte_code = 0;
  while (params[i])
    {
      if (params[i][0] == 'r')
	byte_code = byte_code | (0x40 >> offset);
      else if (params[i][0] == DIRECT_CHAR)
	byte_code = byte_code | (0x80 >> offset);
      else
	byte_code = byte_code | (0xC0 >> offset);
      i++;
      offset += 2;
    }
  return (byte_code);
}

t_instruct	*asm_convert(t_instruct *list)
{
  t_instruct	*tmp;
  int		byte_position;
  int		i;

  tmp = list;
  while (tmp != NULL)
    {
      i = 0;
      byte_position = 0;
      if (tmp->op_code)
	{
	  while (my_strcmp(tmp->op_code, op_tab[i].mnemonique))
	    i++;
	  tmp->binary[byte_position++] = op_tab[i].code;
	  if (has_byte_coding(tmp->op_code))
	    tmp->binary[byte_position++] = define_byte_coding(tmp->params);
	  encode_params(list, tmp, &byte_position);
	  tmp->byte_nbr = byte_position - 1;
	}
      tmp = tmp->nxt;
    }
  return (list);
}
