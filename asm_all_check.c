/*
** asm_all_check.c for asm_all_check in /home/bodart/projets/Tek1/corewar/asm
** 
** Made by louis bodart
** Login   <bodart_l@epitech.net>
** 
** Started on Mon Mar 18 21:29:41 2013 louis bodart
** Last update Sat Mar 30 19:57:10 2013 BODART Louis
*/

#include	<stdlib.h>
#include	"asm.h"
#include	"op.h"
#include	"lib/lib.h"

extern op_t	op_tab[];

static void    	global_check(t_instruct *tmp)
{
  int		i;

  i = 0;
  while (op_tab[i].mnemonique &&
	 my_strcmp(op_tab[i].mnemonique, tmp->op_code))
    i++;
  if (!op_tab[i].mnemonique)
    {
      my_printf(UNKNOWN_MNEMO, tmp->line);
      exit(EXIT_FAILURE);
    }
  i = 0;
  if (tmp->op_code && tmp->params == NULL)
    {
      my_printf(BAD_ARGS_NBR, tmp->line);
      exit(EXIT_FAILURE);
    }
  while (tmp->params[i])
    i++;
  if (i > MAX_ARGS_NUMBER)
    {
      my_printf(TOO_MANY_ARGS, tmp->line);
      exit(EXIT_FAILURE);
    }
}

void		asm_all_check(t_instruct *list)
{
  t_instruct	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      if (tmp->op_code)
	{
	  global_check(tmp);
	  param_nbr_check(tmp);
	  param_type_check(tmp);
	  param_elements_check(list, tmp);
	}
      tmp = tmp->nxt;
    }
}
