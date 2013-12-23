/*
// asm.h for asm in /home/bodart/projets/Tek1/corewar/asm
// 
// Made by louis bodart
// Login   <bodart_l@epitech.net>
// 
// Started on Mon Mar 18 16:45:04 2013 louis bodart
// Last update Sun Mar 31 12:25:37 2013 BODART Louis
*/

#ifndef ASM_H_
# define ASM_H_

#define	OPEN_FAILED	"File '%s' not accessible\n"
#define	UNKNOWN_MNEMO	"Unknown mnemonic at line %d\n"
#define	TOO_MANY_ARGS	"Too many arguments at line %d\n"
#define	BAD_ARGS_NBR	"Bad arguments number line %d\n"
#define	BAD_ARG_TYPE	"Bad argument type at line %d\n"
#define	SYNTAX_ERROR	"Syntax error line %d\n"
#define	BAD_LABEL_CHAR	"Incorrect label char at line %d\n"
#define	LABEL_EXISTS	"Label name already exists at line %d\n"
#define	UNDEFINED_LABEL	"label %s undefine line %d\n"
#define	NAME_PROBLEM	"Name undefined or incorrect\n"
#define	COMMENT_PROBLEM	"Comment undefined or incorrect\n"
#define	UNKNOWN_CMD_STR	"Unknown keyword at line %d\n"

typedef	struct	s_instruct	t_instruct;
typedef	struct	s_infos		t_infos;

struct		s_instruct
{
  int		line;
  int		start_octet;
  char		*label;
  char		*op_code;
  char		**params;
  int		byte_nbr;
  unsigned char	*binary;
  t_instruct	*nxt;
};

struct		s_infos
{
  char		*prog_name;
  char		*comment;
  char		prog_size;
};

void		asm_all_check(t_instruct *);
t_instruct	*asm_convert(t_instruct *);
t_instruct     	*asm_core(t_instruct *, t_infos *, char *);
t_instruct	*asm_line_parser(t_instruct *, char *, int);
void		asm_prog_infos(t_infos *, char *, int);
void		asm_write_file(t_instruct *, t_infos *, char *);
void    	check_prog_infos(t_infos *);
t_instruct     	*define_start_byte(t_instruct *);
int		encode_params(t_instruct *, t_instruct *, int *);
char		*get_label(t_instruct *, char **, int);
char		*get_op_code(char **, char *, int);
char		**get_params(char **, char *, int);
int     	has_byte_coding(char *);
int		is_particular_case(char *);
int     	label_exists(char *, t_instruct *);
void		param_elements_check(t_instruct *, t_instruct *);
void		param_nbr_check(t_instruct *);
void		param_type_check(t_instruct *);

#endif /* !ASM_H_ */
