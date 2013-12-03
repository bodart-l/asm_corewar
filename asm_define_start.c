/*
** asm_define_start.c for asm_define_start in /home/bodart/projets/Tek1/corewar/asm
** 
** Made by louis bodart
** Login   <bodart_l@epitech.net>
** 
** Started on Mon Mar 25 12:54:05 2013 louis bodart
** Last update Sat Mar 30 19:58:21 2013 BODART Louis
*/

#include	<stdlib.h>
#include	"asm.h"
#include	"op.h"

static int     	params_byte(char **params, int is_exception)
{
  int		byte;
  int		i;

  byte = 0;
  i = 0;
  while (params[i])
    {
      if (params[i][0] == 'r')
	byte++;
      else if (params[i][0] == DIRECT_CHAR && is_exception == 0)
	byte += DIR_SIZE;
      else
	byte += IND_SIZE;
      i++;
    }
  return (byte);
}

static int     	instructions_byte(char *instruction, char **params)
{
  if (!my_strcmp(instruction, "live"))
    return (4);
  if (!my_strcmp(instruction, "zjmp"))
    return (params_byte(params, 1));
  if (!my_strcmp(instruction, "ldi") || !my_strcmp(instruction, "lldi"))
    return (params_byte(params, 1));
  if (!my_strcmp(instruction, "sti"))
    return (params_byte(params, 1));
  if (!my_strcmp(instruction, "fork") || !my_strcmp(instruction, "lfork"))
    return (params_byte(params, 1));
  return (params_byte(params, 0));
}

int     	has_byte_coding(char *instruction)
{
  if (!my_strcmp(instruction, "live"))
    return (0);
  if (!my_strcmp(instruction, "zjmp"))
    return (0);
  if (!my_strcmp(instruction, "fork"))
    return (0);
  if (!my_strcmp(instruction, "lfork"))
    return (0);
  return (1);
}

t_instruct     	*define_start_byte(t_instruct *list)
{
  t_instruct	*tmp;
  int		byte;

  tmp = list;
  byte = 0;
  while (tmp != NULL)
    {
      tmp->start_octet = byte;
      if (tmp->op_code)
	{
	  byte++;
	  byte += has_byte_coding(tmp->op_code);
	  byte += instructions_byte(tmp->op_code, tmp->params);
	}
      tmp = tmp->nxt;
    }
  return (list);
}
