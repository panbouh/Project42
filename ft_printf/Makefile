NAME	=	ft_printf

SRC		=	main.c					\
			$(WAY)ft_printf.c		\
			$(WAY)func_flags_basics.c

WAY	=	src/

WAYHEAD	=	./includes/

LIB		=	libft

LIBPATH	=	./libft/

HEADLIBPATH	=	./libft/includes/

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror -I $(HEADLIBPATH) -I $(WAYHEAD) 

CCLIB		=	-L libft/ -lft

RM		=	rm -rf

all		:	$(NAME)

$(NAME)		: $(OBJ) $(LIB)
				$(MAKE) -C $(LIBPATH) all
				gcc $(CFLAGS) -o $(NAME) $(OBJ) $(CCLIB)

lib			:	libft/libft.a
				$(MAKE) -C $(LIBPATH) all

dellib		:
				$(MAKE) -C $(LIBPATH) fclean

clean		:
			$(RM) $(OBJ)

fclean		:	clean
			$(RM) $(NAME)

relib		:
			$(MAKE) -C $(LIBPATH) re

re			:	fclean dellib $(NAME)

.PHONY		:	all re clean fclean lib dellib all relib
