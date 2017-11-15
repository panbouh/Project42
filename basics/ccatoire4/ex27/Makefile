NAME	=	ft_display_file

WAY	=	./src

SRC	=	$(WAY)/main.c				\
		$(WAY)/display_file.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc -o

RM	=	rm -rf

CFLAGS	=	-Wall -Wextra -Werror -I./include

all	: $(NAME)

$(NAME)	: $(OBJ)
	$(CC) $(NAME) $(OBJ) $(CFLAGS)

clean	:
	$(RM) $(OBJ)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all

.PHONY	: all clean fclean re
