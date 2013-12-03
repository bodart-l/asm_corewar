/*
** main.c for main in /home/bodart/projets/SRC
** 
** Made by louis bodart
** Login   <bodart_l@epitech.net>
** 
** Started on Tue Jan  1 14:45:27 2013 louis bodart
** Last update Sat Mar 30 19:56:42 2013 BODART Louis
*/

#include	<stdlib.h>
#include	"lib/lib.h"
#include	"asm.h"
#include	"op.h"

static void	check_op_elements()
{
  if (T_REG != 1 || T_DIR != 2 || T_IND != 4)
    {
      my_printf("Bad value in op.h, please change it\n");
      exit(EXIT_FAILURE);
    }
}

static t_infos 	*init_infos()
{
  t_infos	*infos;

  infos = my_malloc(sizeof(t_infos));
  infos->prog_name = NULL;
  infos->comment = NULL;
  return (infos);
}

int		main(int argc, char **argv)
{
  t_instruct	*list;
  t_infos	*infos;
  char		*file;
  int		i;

  if (argv[1])
    {
      i = 1;
      check_op_elements();
      while (argv[i])
	{
	  list = NULL;
	  infos = init_infos();
	  file = my_strdup(argv[i++]);
	  list = asm_core(list, infos, file);
	  check_prog_infos(infos);
	  asm_all_check(list);
	  list = define_start_byte(list);
	  list = asm_convert(list);
	  asm_write_file(list, infos, file);
	}
    }
  return (EXIT_SUCCESS);
}
