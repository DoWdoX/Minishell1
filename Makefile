##
## Makefile for Makefile in /home/DoWdoX/PROJECT/PSU/PSU_2016_minishell1
## 
## Made by DORIAN DEBOUT
## Login   <DoWdoX@epitech.net>
## 
## Started on  Tue Jan  3 15:18:33 2017 DORIAN DEBOUT
## Last update Fri May  5 18:16:56 2017 DORIAN DEBOUT
##

NAME	=	mysh

SRCS	=	main.c		\
		functions.c	\
		functions2.c	\
		cut_str.c	\
		exec_all.c	\
		verif.c		\
		my_cd_id.c	\
		my_setenv.c	\
		str_to_wordtab.c

OBJS	=	$(SRCS:.c=.o)

CC	=	gcc

RM	=	rm -rf

CFLAGS	+=	-Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -L. -lgnl

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
