NAME	=	fdf

SRC		=	$(WAY)main.c					\
			$(WAY)fdf.c						\
			$(WAY)init.c					\
			$(WAY)input.c

OBJ		=	$(SRC:.c=.o)

WAY	=	src/

WAYHEAD	=	./includes/

LIBFT		=	libft
LIBFTPATH	=	./libft/
HEADLIBFTPATH	=	$(LIBFTPATH)includes/

LIBMLX		=	libmlx
LIBMLXPATH	=	./minilibx/
HEADLIBMLXPATH	=	$(LIBMLXPATH)my_mlx/

CCLIBMLX	=	-I minilibx/ -L minilibx/ -lmlx -framework OpenGL -framework AppKit

CFLAGS	=	-I $(HEADLIBFTPATH) -I $(WAYHEAD) -I $(HEADLIBMLXPATH) -I $(LIBMLXPATH)
#-Wall -Wextra -Werror
CCLIBFT		=	-L libft/ -lft

RM		=	rm -rf

all		:	$(NAME)

$(NAME)		: $(OBJ) $(LIBFT) $(LIBMLX)
				@echo "\033[0;33mBinary < $(NAME) > Creation\033[0m"
				gcc $(CFLAGS) -o $(NAME) $(OBJ) $(CCLIBFT) $(CCLIBMLX)

libft		:	libft/libft.a
				@echo "\033[0;33mLibrary < $(LIBFT).a > Creation\033[0m"
				@$(MAKE) -C $(LIBFTPATH) all

libmlx		:	minilibx/libmlx.a
				@echo "\033[0;33mLibrary < $(LIBMLX).a > Creation\033[0m"
				@$(MAKE) -C $(LIBMLXPATH) all

dellibft		:
				$(MAKE) -C $(LIBFTPATH) fclean

dellibmlx		:
				$(MAKE) -C $(LIBMLXPATH) cclean

clean		:
			$(RM) $(OBJ)

fclean		:	clean
			$(RM) $(NAME)

relibft		:
			$(MAKE) -C $(LIBFTPATH) re

relibmlx		:
			$(MAKE) -C $(LIBMLXPATH) re

re			:	fclean dellib $(NAME)

.PHONY		:	all re clean fclean libft libmlx dellibft dellibmlx all relibft relibmlx
