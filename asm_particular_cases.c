/*
** asm_particular_cases.c for asm_particular_cases in /home/bodart/projets/Tek1/corewar/asm
** 
** Made by louis bodart
** Login   <bodart_l@epitech.net>
** 
** Started on Mon Mar 25 21:59:17 2013 louis bodart
** Last update Sat Mar 30 20:03:01 2013 BODART Louis
*/

#include	<stdlib.h>
#include	"lib/lib.h"
#include	"asm.h"
#include	"op.h"

int		is_particular_case(char *instruction)
{
  if (!my_strcmp(instruction, "zjmp"))
    return (1);
  if (!my_strcmp(instruction, "ldi") || !my_strcmp(instruction, "lldi"))
    return (1);
  if (!my_strcmp(instruction, "sti"))
    return (1);
  if (!my_strcmp(instruction, "fork") || !my_strcmp(instruction, "lfork"))
    return (1);
  return (0);
}
