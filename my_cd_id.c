/*
** commands.c for commands in /home/DoWdoX/PROJECT/PSU/PSU_2016_minishell1
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Fri Jan  6 15:38:53 2017 DORIAN DEBOUT
** Last update Sun Jan 22 14:11:17 2017 DORIAN DEBOUT
*/

#include "./include/my.h"
#include "./gnl.h"

char	*modif_envp(char **envp, int i)
{
  char	*str;

  if ((str = malloc(sizeof(char) * (my_strlen(envp[i]) + 1))) == NULL)
    return NULL;
  str[0] = 'P';
  str[1] = 'W';
  str[2] = 'D';
  str[3] = '=';
  str = my_strcat(str, getcwd(str, my_strlen(envp[i]) + 1));
  return str;
}

void    my_cd(char **tab, char **envp)
{
  int	i;

  i = 0;
  if (tab[1] == '\0')
    {
      if (chdir("/home") == -1)
	write(2, "No such file or directory\n", 26);
    }
  else if (chdir(tab[1]) == -1)
    write(2, "No such file or directory\n", 26);
  my_putstr("Directory: ");
  while (envp[i])
    {
      if (my_strncmp("PWD", envp[i], 3) == 0)
	envp[i] = modif_envp(envp, i);
      i = i + 1;
    }
  pwd(tab[0]);
}

void    pwd(char *str)
{
  char	*aff;

  aff = malloc(sizeof(char) * 32000);
  aff = getcwd(aff, 32000);
  my_putstr(aff);
  my_putchar('\n');
}

void	my_id()
{
  int	child;
  char	**argv;
  char	**argv1;

  argv = malloc(sizeof(char) * 32000);
  argv1 = malloc(sizeof(char) * 32000);
  argv[0] = "/usr/bin/id";
  argv[1] = NULL;
  if (access("/usr/bin/id", R_OK) == 0)
    {
      child = fork();
      argv1[0] = child;
      argv1[1] = NULL;
      execve("/usr/bin/id", argv, argv1);
      wait(&child);
    }
  else
    write(2, "Id failed\n", 10);
}
