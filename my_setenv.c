/*
** commands2.c for commands2 in /home/DoWdoX/PROJECT/PSU/PSU_2016_minishell1
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Wed Jan 11 12:22:49 2017 DORIAN DEBOUT
** Last update Sun Jan 22 17:54:11 2017 DORIAN DEBOUT
*/

#include "./include/my.h"

int	find_env(char **envp, char **tab)
{
  int	i;

  i = 0;
  while (envp[i])
    {
      if (my_strncmp(tab[1], envp[i], my_strlen(tab[1])) == 0)
	return i;
      i = i + 1;
    }
  return 32000;
}

char	**complete(char **envp, char **tab)
{
  int	j;

  j = parse(envp);
  if (tab[2] == NULL)
    {
      envp[j] = my_strcat(tab[1], "=\0");
      envp[j + 1] = NULL;
    }
  else
    {
      envp[j] = my_strcat(tab[1], "=\0");
      envp[j] = my_strcat(envp[j], tab[2]);
    }
  envp[j + 1] = NULL;
  return envp;
}

char	**my_setenv(char **envp, char **tab)
{
  int	i;
  int	j;
  int	k;
  char	*str;

  j = my_strlen(tab[1]);
  if (tab[2] != NULL)
    k = my_strlen(tab[2]);
  else
    k = 0;
  if (find_env(envp, tab) != 32000)
    {
      i = find_env(envp, tab);
      if ((envp[i] = malloc(sizeof(char) * (j + k + 1))) == NULL)
	return NULL;
      envp[i] = my_strcat(tab[1], tab[2]);
    }
  else
    envp = complete(envp, tab);
  return envp;
}
