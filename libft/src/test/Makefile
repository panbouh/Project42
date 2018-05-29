NAME	=	ft_test

SRC		=	main.c

LIB		=	$(LIBPATH)libft.a

LIBPATH	=	../../

HEADLIBPATH	=	$(LIBPATH)includes/

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	 -I $(HEADLIBPATH) -g3

#-Wall -Wextra -Werror

CCLIB		=	-L $(LIBPATH) -lft

RM		=	rm -rf


all		:		$(OBJ)
				$(MAKE) -C $(LIBPATH) all
				gcc $(CFLAGS) -o $(NAME) $(OBJ) $(CCLIB)

lib			:	$(LIB)
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
