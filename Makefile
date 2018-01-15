NAME	=	libftprintf.a

SRC		=	$(WAY)ft_printf.c				\
			$(WAY)func_flags.c				\
			$(WAY)func_calc.c				\
			$(WAY)func_err.c				\
			$(WAY)func_convs_basics.c		\
			$(WAY)func_convs_base.c

WAY	=	src/

WAYHEAD	=	./includes/

LIB		=	libft

LIBFTPATH	=	./libft/

HEADLIBFTPATH	=	./libft/includes/

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	 -I $(HEADLIBFTPATH) -I $(WAYHEAD) 

#-Wall -Wextra -Werror

CCLIBFT		=	-L libft/ -lft

CCLIB		=	-L . -lftprintf

RM		=	rm -rf

all		:	$(NAME)

$(NAME)		: $(OBJ) $(LIB) libft
			@echo "\033[0;33mLibrary < $(NAME) > Creation\033[0m"
			@ar rc $(NAME) $(OBJ)
			@ranlib $(NAME)
			@echo "\033[0;32mLibray < $(NAME) > Correctly Build\033[0m"

test		: main.c $(NAME)
			gcc -o ft_test main.c $(CFLAGS) test.a #$(CCLIB) $(CCLIBFT)

libft		:
				$(MAKE) -C $(LIBFTPATH) all

dellibft	:
				$(MAKE) -C $(LIBFTPATH) fclean

relibft		:
			$(MAKE) -C $(LIBFTPATH) re

clean		:
			$(RM) $(OBJ)

fclean		:	clean
			$(RM) $(NAME)

re			:	fclean dellibft $(NAME)

.PHONY		:	all re clean fclean libft dellibft all relibft test
