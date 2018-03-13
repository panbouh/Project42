NAME	=	ft_ls

SRC		=	$(WAY)main.c					\
			$(WAY)ft_ls.c					\
			$(WAY)init.c					\
			$(WAY)print.c					\
			$(WAY)libft.c					\
			$(WAY)sorting.c					\
			$(WAY)param.c

OBJ		=	$(SRC:.c=.o)

WAY	=	src/

WAYHEAD	=	./includes/

LIBFT		=	libft
LIBFTPATH	=	./libft/
HEADLIBFTPATH	=	$(LIBFTPATH)includes/

CFLAGS	=	-I $(HEADLIBFTPATH) -I $(WAYHEAD)
#-Wall -Wextra -Werror
CCLIBFT		=	-L libft/ -lft

RM		=	rm -rf

all		:	$(NAME)

$(NAME)		: $(OBJ) $(LIBFT)
				@echo "\033[0;33mBinary < $(NAME) > Creation\033[0m"
				gcc $(CFLAGS) -o $(NAME) $(OBJ) $(CCLIBFT)

libft		:	libft/libft.a
				@echo "\033[0;33mLibrary < $(LIBFT).a > Creation\033[0m"
				@$(MAKE) -C $(LIBFTPATH) all

dellibft		:
				$(MAKE) -C $(LIBFTPATH) fclean

clean		:
			$(RM) $(OBJ)

fclean		:	clean
			$(RM) $(NAME)

relibft		:
			$(MAKE) -C $(LIBFTPATH) re

re			:	fclean dellibft $(NAME)

.PHONY		:	all re clean fclean libft dellibft all relibft
