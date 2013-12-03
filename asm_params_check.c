/*
** asm_params_check.c for asm_params_check in /home/bodart/projets/Tek1/corewar/asm
** 
** Made by louis bodart
** Login   <bodart_l@epitech.net>
** 
** Started on Fri Mar 22 22:00:05 2013 louis bodart
** Last update Sat Mar 30 20:05:34 2013 BODART Louis
*/

#include	<stdlib.h>
#include	"asm.h"
#include	"op.h"
#include	"lib/lib.h"

void		param_nbr_check(t_instruct *tmp)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (&op_tab[i] && my_strcmp(op_tab[i].mnemonique, tmp->op_code))
    i++;
  while (tmp->params[j])
    j++;
  if (j != op_tab[i].nbr_args)
    {
      my_printf(BAD_ARGS_NBR, tmp->line);
      exit(EXIT_FAILURE);
    }
}

static int     	authorized_param(char *param, int mode, int line)
{
  if (param[0] && param[0] == 'r')
    {
      if (mode % 2 == 0)
	return (0);
    }
  else if (param[0] && param[0] == DIRECT_CHAR)
    {
      if (mode < T_DIR || (mode == T_IND))
	return (0);
    }
  else
    if (mode < T_IND)
      return (0);
  if (param[0] && param[0] == 'r' || param[0] && param[0] == DIRECT_CHAR)
    if (!param[1])
      {
	my_printf(SYNTAX_ERROR, line);
	exit(EXIT_FAILURE);
      }
  return (1);
}

void		param_type_check(t_instruct *tmp)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (&op_tab[i] && my_strcmp(op_tab[i].mnemonique, tmp->op_code))
    i++;
  while (tmp->params[j])
    {
      if (op_tab[i].type[j] != 7)
	if (!authorized_param(tmp->params[j], op_tab[i].type[j], tmp->line))
	  {
	    my_printf(BAD_ARG_TYPE, tmp->line);
	    exit(EXIT_FAILURE);
	  }
      j++;
    }
}

static int     	element_is_valid(char *element, t_instruct *list, int line)
{
  char		*tmp;

  if (element[0] && element[0] == LABEL_CHAR)
    {
      tmp = my_strcut(element, 1);
      if (!label_exists(tmp, list))
	{
	  my_printf(UNDEFINED_LABEL, tmp, line);
	  exit(EXIT_FAILURE);
	}
    }
  if (element[0] && element[0] == DIRECT_CHAR)
    {
      tmp = my_strcut(element, 1);
      if (tmp[0] && tmp[0] == LABEL_CHAR)
	{
	  tmp = my_strcut(tmp, 1);
	  if (!label_exists(tmp, list))
	    {
	      my_printf(UNDEFINED_LABEL, tmp, line);
	      exit(EXIT_FAILURE);
	    }
	}
    }
}

void		param_elements_check(t_instruct *list, t_instruct *tmp)
{
  int		i;

  i = 0;
  while (tmp->params[i])
    {
      if (tmp->params[i][0] == 'r')
	if (tmp->params[i][1] != LABEL_CHAR)
	  my_is_num(tmp->params[i], 1, tmp->line);
      if (tmp->params[i][0] == DIRECT_CHAR)
	if (tmp->params[i][1] != LABEL_CHAR)
	  my_is_num(tmp->params[i], 1, tmp->line);
      if (tmp->params[i][0] != DIRECT_CHAR && tmp->params[i][0] != 'r')
	if (tmp->params[i][0] != LABEL_CHAR)
	  my_is_num(tmp->params[i], 0, tmp->line);
      element_is_valid(tmp->params[i++], list, tmp->line);
    }
}
