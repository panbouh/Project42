NAME	=	ft_ls

SRC_NAME	=	main.c		\
				minishell.c


SRC_PATH	=	src

OBJ_NAME	=	$(SRC_NAME:.c=.o)
OBJ_PATH	=	obj

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

HEADPATH	=	./includes/

LIBFTNAME	=	libft
LIBFTPATH	=	./libft/
LIBFT		=	$(LIBFTPATH)$(LIBFTNAME).a
HEADLIBFTPATH	=	$(LIBFTPATH)includes/

CFLAGS	=	-I $(HEADLIBFTPATH) -I $(HEADPATH) -Wall -Wextra -Werror

CCLIBFT		=	-L libft/ -lft

RM		=	rm -rf

all		:	$(NAME)

$(NAME)		:  $(LIBFT) $(OBJ)
				@echo "\033[0;33mBinary < $(NAME) > Creation\033[0m"
				gcc $(CFLAGS) -o $(NAME) $(OBJ) $(CCLIBFT)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
				@mkdir $(OBJ_PATH) 2> /dev/null || true
				gcc $(CFLAGS) $(CCLIBFT) -o $ -c $<

$(LIBFT)	:
				@echo "\033[0;33mLibrary < $(LIBFT).a > Creation\033[0m"
				@$(MAKE) -C $(LIBFTPATH) all

norme:
		norminette $(SRC)
		norminette $(HEADPATH)

dellibft	:
				$(MAKE) -C $(LIBFTPATH) fclean

clean		:
			$(RM) $(OBJ)
			@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean		: clean
			$(RM) $(NAME)

destroy		: fclean dellibft

relibft		:
			$(MAKE) -C $(LIBFTPATH) re

re			: fclean $(NAME)

reset		: relibft re


.PHONY		:	all re clean fclean dellibft all relibft destroy reset
