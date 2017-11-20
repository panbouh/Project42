NAME	=	fdf

SRC		=	$(WAY)main.c					\
			$(WAY)fdf.c

OBJ		=	$(SRC:.c=.o)

WAY	=	src/

WAYHEAD	=	./includes/

LIBFT		=	libft
LIBFTPATH	=	./libft/
HEADLIBPATH	=	./libft/includes/

#LIBMLX		=	-I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
LIBMLX		=	-I minilibx/ -L minilibx/ -lmlx -framework OpenGL -framework AppKit

CFLAGS	=	-Wall -Wextra -Werror -I $(HEADLIBPATH) -I $(WAYHEAD)

CCLIB		=	-L libft/ -lft

RM		=	rm -rf

all		:	$(NAME)

$(NAME)		: $(OBJ) $(LIBFT)
				echo "EH SALUT"
				$(MAKE) -C $(LIBFTPATH) all
				gcc $(CFLAGS) -o $(NAME) $(OBJ) $(CCLIB)  $(LIBMLX)

lib			:	libft/libft.a
				$(MAKE) -C $(LIBFTPATH) all

dellib		:
				$(MAKE) -C $(LIBFTPATH) fclean

clean		:
			$(RM) $(OBJ)

fclean		:	clean
			$(RM) $(NAME)

relib		:
			$(MAKE) -C $(LIBFTPATH) re

re			:	fclean dellib $(NAME)

.PHONY		:	all re clean fclean lib dellib all relib
