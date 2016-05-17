CC	= gcc
NAME	= my_ls
SRC	=	fonction.c\
			fonction2.c\
			main.c\
			fonction_ls.c\
			ls_l.c\
			fonction_ls_2.c\
			fonction3.c


OBJ	= $(SRC:%.c=%.o)
RM	= rm -f
CFLAGS	+= -W -Wall -Werror -ansi -pedantic

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:	fclean all
