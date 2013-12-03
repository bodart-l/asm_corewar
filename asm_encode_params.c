/*
** asm_encode_params.c for asm_encode_params in /home/bodart/projets/Tek1/corewar/asm
** 
** Made by louis bodart
** Login   <bodart_l@epitech.net>
** 
** Started on Mon Mar 25 17:07:11 2013 louis bodart
** Last update Sat Mar 30 19:59:17 2013 BODART Louis
*/

#include	<stdlib.h>
#include	"lib/lib.h"
#include	"asm.h"
#include	"op.h"

static int     	byte_diff(t_instruct *list, t_instruct *current,
			  char *end_pre_label, int byte_position)
{
  char		*end_label;
  t_instruct	*tmp;
  int		difference;

  tmp = list;
  end_label = my_strcut(end_pre_label, 1);
  while (tmp != NULL &&
	 (tmp->label == NULL || my_strcmp(tmp->label, end_label)))
    tmp = tmp->nxt;
  if (tmp == NULL)
    exit(EXIT_FAILURE);
  difference =  (tmp->start_octet) - (current->start_octet);
  return (difference);
}

static void    	push_in_binary(t_instruct *tmp, int value,
			       int *byte_position, int size)
{
  int		i;
  int		position;

  if (size == IND_SIZE && value > IDX_MOD)
    my_printf("Warning Indirection to far line %d\n", tmp->line);
  if (size == 1 && (value <= 0 || value > REG_NUMBER))
    {
      my_printf("no such register line %d\n", tmp->line);
      exit(EXIT_FAILURE);
    }
  i = size - 1;
  position = *byte_position;
  while (position <= size)
    tmp->binary[position++] = 0;
  while (i >= 0)
    tmp->binary[(*byte_position)++] = value >> (8 * i--);
}

static void    	classic_params_bytes(t_instruct *list, t_instruct *tmp,
				     int *byte_position, int i)
{
  char		*str;

  if (tmp->params[i][0] == 'r' || tmp->params[i][0] == DIRECT_CHAR)
    {
      str = my_strcut(tmp->params[i], 1);
      if (tmp->params[i][0] == 'r')
	if (str[0] == LABEL_CHAR)
	  push_in_binary(tmp, byte_diff(list, tmp, str, *byte_position),
			 byte_position, 1);
	else
	  push_in_binary(tmp, my_atoi(str), byte_position, 1);
      else
	if (str[0] == LABEL_CHAR)
	  push_in_binary(tmp, byte_diff(list, tmp, str, *byte_position),
			 byte_position, DIR_SIZE);
	else
	  push_in_binary(tmp, my_atoi(str), byte_position, DIR_SIZE);
      free(str);
    }
  else
    if (tmp->params[i][0] == LABEL_CHAR)
      push_in_binary(tmp, byte_diff(list, tmp, tmp->params[i], *byte_position),
		     byte_position, IND_SIZE);
    else
      push_in_binary(tmp, my_atoi(tmp->params[i]), byte_position, IND_SIZE);
}

static void    	particular_params_bytes(t_instruct *list, t_instruct *tmp,
					int *byte_position, int i)
{
  char		*str;

  if (tmp->params[i][0] == 'r')
    {
      str = my_strcut(tmp->params[i], 1);
      if (str[0] == LABEL_CHAR)
	push_in_binary(tmp, byte_diff(list, tmp, str, *byte_position),
		       byte_position, 1);
      else
	push_in_binary(tmp, my_atoi(str), byte_position, 1);
    }
  else
    {
      if (tmp->params[i][0] == DIRECT_CHAR)
	str = my_strcut(tmp->params[i], 1);
      else
	str = tmp->params[i];
      if (str[0] == LABEL_CHAR)
	push_in_binary(tmp, byte_diff(list, tmp, str, *byte_position),
		       byte_position, IND_SIZE);
      else
	push_in_binary(tmp, my_atoi(str), byte_position, IND_SIZE);
    }
}

int		encode_params(t_instruct *list, t_instruct *tmp,
			      int *byte_position)
{
  char		*str;
  int		i;

  i = 0;
  if (is_particular_case(tmp->op_code))
    {
      while (tmp->params[i])
	particular_params_bytes(list, tmp, byte_position, i++);
      return (1);
    }
  while (tmp->params[i])
    classic_params_bytes(list, tmp, byte_position, i++);
  return (0);
}
