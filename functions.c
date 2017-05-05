/*
** functions.c for functions.c in /home/DoWdoX/PROJECT/PSU/PSU_2016_minishell1
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Thu Jan  5 16:22:25 2017 DORIAN DEBOUT
** Last update Sun Jan 22 19:30:06 2017 DORIAN DEBOUT
*/

#include "./include/my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  return (0);
}

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  i = 0;
  while (dest[i] != '\0')
    i = i + 1;
  j = 0;
  while (src[j] != '\0')
    {
      dest[i] = src[j];
      i = i + 1;
      j = j + 1;
    }
  dest[i] = '\0';
  return (dest);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i = i + 1;
  return (i);
}

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0' && i < n)
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i = i + 1;
    }
  return (s1[i] - s2[i]);
}
