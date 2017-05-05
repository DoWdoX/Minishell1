/*
** verif.c for verif in /home/DoWdoX/PROJECT/PSU/clone2
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Sat Jan 21 18:27:13 2017 DORIAN DEBOUT
** Last update Sun Jan 22 19:34:25 2017 DORIAN DEBOUT
*/

#include "./include/my.h"

int	verif(char *str)
{
  int	i;

  i = nbr_word(str);
  if (i == 0)
    return 1;
  else
    return 0;
}
