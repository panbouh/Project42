NAME	=	ft_ls

SRC		=	$(WAY)main.c					\
			$(WAY)ft_ls.c					\
			$(WAY)init.c					\
			$(WAY)print.c					\
			$(WAY)sort_file.c				\
			$(WAY)sort_dir.c				\
			$(WAY)error.c					\
			$(WAY)get.c						\
			$(WAY)get2.c					\
			$(WAY)utils.c					\
			$(WAY)param.c

OBJ		=	$(SRC:.c=.o)

WAY	=	src/

HEADPATH	=	./includes/

LIBFT		=	libft
LIBFTPATH	=	./libft/
HEADLIBFTPATH	=	$(LIBFTPATH)includes/

CFLAGS	=	-I $(HEADLIBFTPATH) -I $(HEADPATH)
#-Wall -Wextra -Werror
CCLIBFT		=	-L libft/ -lft

RM		=	rm -rf

all		:	$(NAME)

$(NAME)		: $(LIBFT) $(OBJ) $(HEADPATH)ft_ls.h
				@echo "\033[0;33mBinary < $(NAME) > Creation\033[0m"
				gcc $(CFLAGS) -o $(NAME) $(OBJ) $(CCLIBFT)

libft		:
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

re			:	fclean $(NAME)

.PHONY		:	all re clean fclean libft dellibft all relibft
