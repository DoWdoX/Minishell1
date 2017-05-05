/*
** functions2.c for functions2 in /home/DoWdoX/PROJECT/PSU/clone2
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Sat Jan 21 16:03:39 2017 DORIAN DEBOUT
** Last update Sun Jan 22 19:30:18 2017 DORIAN DEBOUT
*/

#include "./include/my.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0')
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i = i + 1;
    }
  return (s1[i] - s2[i]);
}
