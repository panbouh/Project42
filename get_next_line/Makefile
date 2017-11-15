NAME	=	dada

SRC		=	main.c				\
			$(WAY)get_next_line.c

WAY	=	git/

WAYTWO	= ~/rendu/

OBJ		=	$(SRC:.c=.o)

CC		=	gcc -o

CFLAGS	=	-Wall -Wextra -Werror -fsanitize=address

#-I./include

RM		=	rm -rf

all		:	$(NAME)

#$(CC) -c $(OBJ) $(CFLAGS)

$(NAME)		:	$(SRC)
			clang -Wall -Wextra -Werror -I $(WAY)libft/includes -o $(WAY)get_next_line.o -c $(WAY)get_next_line.c
			clang -Wall -Wextra -Werror -I $(WAY)libft/includes -o main.o -c main.c
			clang -o test_gnl main.o $(WAY)get_next_line.o -I $(WAY)libft/includes -L $(WAY)libft/ -lft

test		:
			gcc test.c -I $(WAY)libft/includes -L $(WAY)libft/ -lft

lib			:
			@(cd ~/rendu/libft && $(MAKE))

dellib		:
			@(cd ~/rendu/libft && $(MAKE) fclean)

clean		:
			$(RM) $(OBJ)

fclean		:	clean
			$(RM) $(NAME)

relib		:
			@(cd ~/rendu/libft && $(MAKE) re)

re			:	fclean $(NAME)

.PHONY		:	re clean fclean
