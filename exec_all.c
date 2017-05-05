/*
** exec_all.c for exec_all in /home/DoWdoX/PROJECT/PSU/clone2
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Sat Jan 21 16:24:24 2017 DORIAN DEBOUT
** Last update Fri May  5 18:22:03 2017 DORIAN DEBOUT
*/

#include "./include/my.h"

char	*commands(char *ag1, char **tab)
{
  int	i;

  if (my_strncmp("/bin", tab[0], 3) == 0)
    return ag1;
  if (tab[0][0] != '/' && tab[0][0] != '.')
    {
      ag1[0] = '/';
      ag1[1] = 'b';
      ag1[2] = 'i';
      ag1[3] = 'n';
      ag1[4] = '/';
    }
  ag1 = my_strcat(ag1, tab[0]);
  i = my_strlen(ag1);
  ag1[i + 1] = '\0';
  return ag1;
}

int	parse(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i = i + 1;
  return i;
}

char	**complete_ag2(char **tab, char **ag2)
{
  int	i;
  int	k;

  k = 0;
  i = parse(tab);
  while (k != i)
    {
      if ((ag2[k] = malloc(sizeof(char) * (my_strlen(tab[k]) + 1))) == NULL)
	return NULL;
      ag2[k] = my_strcat(ag2[k], tab[k]);
      k = k + 1;
    }
  return ag2;
}

void	aff(char **tab)
{
  int	i;

  i = 0;
  if (tab[i] == NULL)
    {
      my_putchar('\n');
      my_putstr("$> ");
    }
  else
    {
      while (tab[i])
	{
	  my_putstr(tab[i]);
	  if (i != parse(tab) - 1)
	    my_putchar(' ');
	  i = i + 1;
	}
      my_putstr(": Command not found\n");
    }
}

char	**exec_all(char **tab, pid_t pid)
{
  char	*ag1;
  char	**ag2;
  char	**ag3;
  int	i;

  i = parse(tab);
  if ((ag1 = malloc(sizeof(char) * (my_strlen(tab[0]) + 6))) == NULL)
    return NULL;
  if ((ag2 = malloc(sizeof(char*) * (i + 1))) == NULL)
    return NULL;
  ag3 = malloc(sizeof(char*) * (i + 1));
  ag1 = commands(ag1, tab);
  ag2 = complete_ag2(tab, ag2);
  if (access(ag1, R_OK) == 0)
    {
      pid = fork();
      ag3[0] = pid;
      ag3[1] = NULL;
      execve(ag1, ag2, ag3);
      if (WTERMSIG(pid) == 11)
	write(2, "Segmentation fault (core dumped)\n", 33);
      wait(&pid);
    }
  else
    aff(tab);
}
