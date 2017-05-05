/*
** cut_str.c for cut_spaces_tab in /home/DoWdoX/PROJECT/PSU/clone2
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Sat Jan 21 15:39:56 2017 DORIAN DEBOUT
** Last update Sun Jan 22 15:05:03 2017 DORIAN DEBOUT
*/

#include "./include/my.h"

int	cut_begin(char *str)
{
  int	i;

  i = 0;
  if (str[i] == ' ' || str[i] == '\t')
    {
      while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
	i = i + 1;
    }
  return i;
}

int	cut_end(char *str)
{
  int	i;

  i = my_strlen(str) - 1;
  if (str[i] == ' ' || str[i] == '\t')
    {
      while (i > 0 && (str[i] == ' ' || str[i] == '\t'))
	i = i - 1;
    }
  i = i + 1;
  return i;
}

char	*cut_str(char *str)
{
  int	i;
  int	j;
  int	k;
  char	*str2;

  k = 0;
  if (verif(str) == 0)
    {
      i = cut_begin(str);
      j = cut_end(str);
      if ((str2 = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
	return NULL;
      while (i != j)
	{
	  str2[k] = str[i];
	  k = k + 1;
	  i = i + 1;
	}
      return str2;
    }
  else
    return NULL;
}
