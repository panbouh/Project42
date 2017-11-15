# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/23 16:01:55 by ccatoire          #+#    #+#              #
#    Updated: 2017/04/24 14:11:12 by ccatoire         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRC		=	$(PA)/ft_putchar.c			\
			$(PA)/ft_putstr.c			\
			$(PA)/ft_strcmp.c			\
			$(PA)/ft_strlen.c			\
			$(PA)/ft_swap.c

CC		=	gcc -c

PA		=   srcs

FLAGS		=	-I./include

RM		=	rm -rf

OBJ		=	$(SRC:.c=.o)

all		:	$(NAME)

$(NAME) :		$(OBJ)
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)

clean	:
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)

re		: 	fclean all

.PHONY	:	all clean fclean re
