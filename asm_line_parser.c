/*
** asm_line_parser.c for asm_line_parser in /home/bodart/projets/Tek1/corewar/asm
** 
** Made by louis bodart
** Login   <bodart_l@epitech.net>
** 
** Started on Mon Mar 18 17:55:36 2013 louis bodart
** Last update Sat Mar 30 20:01:05 2013 BODART Louis
*/

#include	<stdlib.h>
#include	"asm.h"
#include	"op.h"
#include	"lib/lib.h"

static int     	get_max()
{
  int		max;

  max = IND_SIZE;
  if (REG_SIZE > max)
    max = REG_SIZE;
  if (DIR_SIZE > max)
    max = DIR_SIZE;
  return (max * MAX_ARGS_NUMBER);
}

static void    	check_elements(char **elements, char *label)
{
  char		*tmp;
  int		max_parts;
  int		i;

  i = 0;
  if (label == NULL)
    max_parts = 1;
  else
    max_parts = 2;
  while (elements[i])
    i++;
  if (i > max_parts)
    {
      i = max_parts;
      tmp = elements[i++];
      while (elements[i])
	tmp = my_strcat(tmp, elements[i++]);
      elements[max_parts] = tmp;
    }
}

t_instruct	*asm_line_parser(t_instruct *list, char *instruct, int line_nbr)
{
  t_instruct	*new_element;
  t_instruct	*tmp;
  char		**elements;

  elements = my_explode(instruct, ' ');
  new_element = my_malloc(sizeof(t_instruct));
  new_element->line = line_nbr;
  new_element->label = get_label(list, elements, line_nbr);
  check_elements(elements, new_element->label);
  new_element->op_code = get_op_code(elements, new_element->label, line_nbr);
  new_element->params = get_params(elements, new_element->label, line_nbr);
  new_element->binary = my_malloc(sizeof(unsigned char) * (get_max() + 3));
  new_element->nxt = NULL;
  free(elements);
  if (list == NULL)
    return (new_element);
  tmp = list;
  while (tmp->nxt != NULL)
    tmp = tmp->nxt;
  tmp->nxt = new_element;
  return (list);
}
