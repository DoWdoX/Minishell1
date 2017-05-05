/*
** my.h for my.h in /home/DoWdoX/PROJECT/PSU/PSU_2016_minishell1/include
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Thu Jan  5 16:23:35 2017 DORIAN DEBOUT
** Last update Fri May  5 18:22:13 2017 DORIAN DEBOUT
*/

#ifndef MY_H
#define MY_H

#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>

void	my_putchar(char c);
int	my_putstr(char *str);
char	*my_strcat(char *dest, char *src);
int	my_strlen(char *str);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int n);
char	**str_wordtab(char *str);
char	*cut_str(char *str);
char	**exec_all(char **tab, pid_t pid);
int	verif(char *str);
void	my_cd(char **tab, char **envp);
void	pwd(char *str);
void	my_id();
int	nbr_word(char *str);
char	**my_setenv(char **envp, char **tab);
int	parse(char **tab);

#endif
