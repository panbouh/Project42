NAME	=	laKaisse

SRC		=	main.c					\
			$(WAY)laKaisse.c		\
			$(WAY)print.c		\
			$(WAY)init.c		\
			~/rendu/get_next_line/git/get_next_line.c

WAY	=	

LIB		=	$(LIBPATH)libft.a

LIBPATH	=	~/rendu/libft/

HEADLIBPATH	=	$(LIBPATH)includes/

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror -I $(HEADLIBPATH)

CCLIB		=	-L $(LIBPATH) -lft

RM		=	rm -rf

all		:	$(NAME)

$(NAME)		: $(OBJ)
				$(MAKE) -C $(LIBPATH) all
				gcc $(CFLAGS) -o $(NAME) $(OBJ) $(CCLIB) -I $(HEADLIBPATH)

lib			:
				$(MAKE) -C $(LIBPATH) all

dellib		:
				$(MAKE) -C $(LIBPATH) fclean

clean		:
			$(RM) $(OBJ)

fclean		:	clean
			$(RM) $(NAME)

relib		:
			$(MAKE) -C $(LIBPATH) re

re			:	fclean $(NAME)

.PHONY		:	all re clean fclean lib dellib all relib
