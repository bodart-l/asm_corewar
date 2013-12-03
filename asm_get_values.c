/*
** asm_get_values.c for asm_get_values in /home/bodart/projets/Tek1/corewar/asm
** 
** Made by louis bodart
** Login   <bodart_l@epitech.net>
** 
** Started on Mon Mar 18 18:05:25 2013 louis bodart
** Last update Sat Mar 30 19:59:46 2013 BODART Louis
*/

#include	<stdlib.h>
#include	"asm.h"
#include	"op.h"
#include	"lib/lib.h"

int     	label_exists(char *label, t_instruct *list)
{
  t_instruct	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      if (tmp->label != NULL)
	if (!my_strcmp(tmp->label, label))
	  return (1);
      tmp = tmp->nxt;
    }
  return (0);
}

static void    	check_label_name(char *label, int line_nbr)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (label[i])
    {
      j = 0;
      while (LABEL_CHARS[j] && LABEL_CHARS[j] != label[i])
	j++;
      if (!LABEL_CHARS[j])
	{
	  my_printf(BAD_LABEL_CHAR, line_nbr);
	  exit(EXIT_FAILURE);
	}
      i++;
    }
}

char		*get_label(t_instruct *list, char **elements, int line_nbr)
{
  char		*label;
  int		i;
  int		j;

  if (!my_count_char(elements[0], LABEL_CHAR))
    return (NULL);
  i = 0;
  label = my_malloc(sizeof(char) * (my_strlen(elements[i]) + 1));
  while (elements[0][i] && elements[0][i] != LABEL_CHAR)
    label[i] = elements[0][i++];
  label[i] = '\0';
  check_label_name(label, line_nbr);
  if (label_exists(label, list))
    {
      my_printf(LABEL_EXISTS, line_nbr);
      exit(EXIT_FAILURE);
    }
  return (label);
}

char		*get_op_code(char **elements, char *label, int line_nbr)
{
  int		i;

  i = 0;
  if (label == NULL)
    {
      if (!elements[0])
	return (NULL);
      return (elements[0]);
    }
  if (!elements[1])
    return (NULL);
  return (elements[1]);
}

char		**get_params(char **elements, char *label, int line_nbr)
{
  char		**params;

  if (!elements[1])
    return (NULL);
  if (label == NULL)
    {
      if (!elements[1])
	return (NULL);
      params = my_explode(elements[1], SEPARATOR_CHAR);
      return (params);
    }
  if (!elements[2])
    return (NULL);
  params = my_explode(elements[2], SEPARATOR_CHAR);
  return (params);
}
