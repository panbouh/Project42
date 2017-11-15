NAME	=	do-op

WAY	=	./src

SRC	=	$(WAY)/main.c						\
		$(WAY)/do_op.c						\
		$(WAY)/print.c						\
		$(WAY)/tool.c						#\

OBJ	=	$(SRC:.c=.o)

CC	=	gcc -o

RM	=	rm -rf

CFLAGS	=	-Wall -Wextra -Werror -I./include

all	: $(NAME)

$(NAME)	: $(OBJ)
	$(CC) $(NAME) $(OBJ)

clean	:
	$(RM) $(OBJ)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all

.PHONY	: all $(NAME) clean fclean re
