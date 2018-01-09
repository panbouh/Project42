NAME	=	ft_printf

SRC		=	main.c							\
			$(WAY)ft_printf.c				\
			$(WAY)func_flags.c				\
			$(WAY)func_calc.c				\
			$(WAY)func_err.c				\
			$(WAY)func_convs_basics.c		\
			$(WAY)func_convs_base.c

WAY	=	src/

WAYHEAD	=	./includes/

LIB		=	libft

LIBPATH	=	./libft/

HEADLIBPATH	=	./libft/includes/

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	 -I $(HEADLIBPATH) -I $(WAYHEAD) 

#-Wall -Wextra -Werror

CCLIB		=	-L libft/ -lft

RM		=	rm -rf

all		:	$(NAME)

$(NAME)		: $(OBJ) $(LIB) lib
				$(MAKE) -C $(LIBPATH) all
				gcc $(CFLAGS) -o $(NAME) $(OBJ) $(CCLIB)

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

re			:	fclean dellib $(NAME)

.PHONY		:	all re clean fclean lib dellib all relib
