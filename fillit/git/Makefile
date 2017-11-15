NAME	=	fillit

SRC		=	main.c					\
			$(WAY)fillit.c 			\
			$(WAY)ft_init.c 		\
			$(WAY)ft_init2.c 		\
			$(WAY)ft_checkshape.c 	\
			$(WAY)ft_print.c 		\
			$(WAY)ft_check_n_put.c

WAY	=	

LIB		=	libft

LIBPATH	=	./libft/

HEADLIBPATH	=	./libft/includes/

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror -I $(HEADLIBPATH)

CCLIB		=	-L libft/ -lft

RM		=	rm -rf

all		:	$(NAME)

$(NAME)		: $(OBJ) $(LIB)
				$(MAKE) -C $(LIBPATH) all
				gcc $(CFLAGS) -o $(NAME) $(OBJ) $(CCLIB) -I $(HEADLIBPATH)

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
