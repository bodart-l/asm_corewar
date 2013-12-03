/*
** asm_write_file.c for asm_write_file in /home/bodart/projets/Tek1/corewar/asm
** 
** Made by louis bodart
** Login   <bodart_l@epitech.net>
** 
** Started on Mon Mar 25 23:27:41 2013 louis bodart
** Last update Sat Mar 30 20:04:23 2013 BODART Louis
*/

#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"asm.h"
#include	"op.h"
#include	"lib/lib.h"

static int     	convert_char_to_int(unsigned char *str)
{
  int		result;

  result = ((str[0] << (8 * 3)) & 0xFF000000) |
    ((str[1] << (8 * 2)) & 0x00FF0000) |
    ((str[2] << (8)) & 0x0000FF00) |
    ((str[3] & 0x000000FF));
  return (result);
}

static int     	manage_endianness(header_t *header, int value)
{
  unsigned char	tab[4];
  int		i;

  i = 0;
  while (i <= 3)
    {
      tab[i++] = value % 256;
      value /= 256;
    }
  return (convert_char_to_int(tab));
}

static void    	write_header(t_instruct *list, t_infos *infos, int fd)
{
  t_instruct	*tmp;
  int		i;
  header_t	header;
  int		prog_size;

  i = 0;
  tmp = list;
  header.magic = manage_endianness(&header, COREWAR_EXEC_MAGIC);
  while (i <= PROG_NAME_LENGTH)
    if (i++ < my_strlen(infos->prog_name))
      header.prog_name[i - 1] = infos->prog_name[i - 1];
    else
      header.prog_name[i - 1] = 0;
  i = 0;
  while (i <= COMMENT_LENGTH)
    if (i++ < my_strlen(infos->comment))
      header.comment[i - 1] = infos->comment[i - 1];
    else
      header.comment[i - 1] = 0;
  while (tmp->nxt != NULL)
    tmp = tmp->nxt;
  prog_size = tmp->start_octet + (tmp->byte_nbr + 1);
  header.prog_size = manage_endianness(&header, prog_size);
  write(fd, &header, sizeof(header_t));
}

static char    	*define_out_path(char *file)
{
  int		i;
  int		point;
  int		current;
  char		*cor_name;

  i = 0;
  current = 0;
  point = my_count_char(file, '.');
  while (current < point)
    if (file[i++] == '.')
      current++;
  file[i] = '\0';
  cor_name = my_strcat(file, "cor");
  free(file);
  return (cor_name);
}

void		asm_write_file(t_instruct *list, t_infos *infos, char *file)
{
  int		fd;
  char		**tab;
  char		*cor_name;
  t_instruct	*tmp;
  t_instruct	*ptr;

  tmp = list;
  cor_name = define_out_path(file);
  fd = open(cor_name, O_CREAT | O_RDWR | O_TRUNC, 0664);
  if (list == NULL)
    {
      my_printf("No instruction in file\n");
      exit(EXIT_FAILURE);
    }
  my_printf("Assembling '%s' ...\n", infos->prog_name);
  write_header(list, infos, fd);
  while (tmp != NULL)
    {
      ptr = tmp;
      if (tmp->op_code)
	write(fd, tmp->binary, tmp->byte_nbr + 1);
      tmp = tmp->nxt;
      free(ptr);
    }
}
