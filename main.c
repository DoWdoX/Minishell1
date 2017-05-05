/*
** main.c for main in /home/DoWdoX/PROJECT/PSU/PSU_2016_minishell1
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Thu Jan  5 16:17:00 2017 DORIAN DEBOUT
** Last update Fri May  5 18:23:28 2017 DORIAN DEBOUT
*/

#include "./include/my.h"
#include "./gnl.h"

void	printab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i = i + 1;
    }
}

void	command(char **tab, pid_t pid, char **envp)
{
  if (my_strcmp("exit", tab[0]) == 0)
    {
      my_putstr("exit\n");
      exit(0);
    }
  else if (my_strncmp("env", tab[0], 3) == 0)
    printab(envp);
  else if (my_strncmp("setenv", tab[0], 6) == 0)
    envp = my_setenv(envp, tab);
  else if (my_strncmp("cd", tab[0], 2) == 0)
    my_cd(tab, envp);
  else if (my_strncmp("id", tab[0], 2) == 0)
    my_id();
  else
    exec_all(tab, pid);
}

void	my_ctrl()
{
  my_putstr("\n$> ");
}

int	main(int ac, char **av, char **envp)
{
  char	*s;
  pid_t	pid;
  char	**tab;

  my_putstr("$> ");
  signal(SIGINT, my_ctrl);
  while ((s = get_next_line(0)) != NULL)
    {
      tab = str_wordtab(s);
      pid = getpid();
      command(tab, pid, envp);
      free(s);
      my_putstr("$> ");
    }
  return (0);
}
