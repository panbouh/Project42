# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/25 13:31:46 by ccatoire          #+#    #+#              #
#    Updated: 2017/03/28 13:32:12 by ccatoire         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	colle-2

WAY	=	src

SRC	=	$(WAY)/main.c				\
		$(WAY)/print_tool.c				\
		$(WAY)/get_out.c			\
		$(WAY)/get_tab.c			#\

OBJ	=	$(SRC:.c=.o)

CC	=	gcc -o

RM	=	rm -rf

CFLAGS	=	-Wall -Wextra -Werror -I./include

all	: $(NAME)

$(NAME)	: $(OBJ)
	$(CC) $(NAME) $(OBJ) $(CFLAGS)

clean	:
	$(RM) $(OBJ)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all

.PHONY	: all $(NAME) clean fclean re
