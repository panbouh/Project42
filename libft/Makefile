################################################################################
#####                                LIBFT                                 #####
################################################################################

NAME		=	libft.a

###################
## PATH SRC FILE ##
###################
SRC_PATH	=	./src/
INC_PATH	=	./includes/

#Add new folder here
SRC_CHECK	=	$(addprefix $(SRC_PATH),checking/)
SRC_LIST	=	$(addprefix $(SRC_PATH),list/)
SRC_MATH	=	$(addprefix $(SRC_PATH),math/)
SRC_MEM		=	$(addprefix $(SRC_PATH),memory/)
SRC_MORPH	=	$(addprefix $(SRC_PATH),morphing/)
SRC_PRINT	=	$(addprefix $(SRC_PATH),print/)
SRC_STR		=	$(addprefix $(SRC_PATH),str/)
SRC_FILE	=	$(addprefix $(SRC_PATH),file/)

#PATH MIXED
SRC		=	$(addprefix $(SRC_CHECK),$(CHECK_FILE))		\
			$(addprefix $(SRC_LIST),$(LIST_FILE))		\
			$(addprefix $(SRC_MATH),$(MATH_FILE))		\
			$(addprefix $(SRC_MEM),$(MEM_FILE))			\
			$(addprefix $(SRC_MORPH),$(MORPH_FILE))		\
			$(addprefix $(SRC_PRINT),$(PRINT_FILE))		\
			$(addprefix $(SRC_STR),$(STR_FILE))			\
			$(addprefix $(SRC_FILE),$(FILE_FILE))


INC		=	$(addprefix $(INC_PATH),$(HEAD))

##############
## SRC FILE ##
##############

CHECK_FILE	=	ft_isalpha.c							\
				ft_isdigit.c							\
				ft_isalnum.c							\
				ft_isascii.c							\
				ft_isprint.c

LIST_FILE	=	ft_lstnew.c								\
				ft_lstdelone.c							\
				ft_lstdel.c								\
				ft_lstadd.c								\
				ft_lstiter.c							\
				ft_lstmap.c

MATH_FILE	=	ft_power.c								\
				ft_count_digit.c						\
				ft_abs.c								\
				ft_conv_n_base.c

MEM_FILE	=	ft_memset.c								\
				ft_bzero.c								\
				ft_memcpy.c								\
				ft_memccpy.c							\
				ft_memmove.c							\
				ft_memchr.c								\
				ft_memcmp.c								\
				ft_memalloc.c							\
				ft_memdel.c

MORPH_FILE	=	ft_atoi.c								\
				ft_itoa.c								\
				ft_toupper.c							\
				ft_tolower.c							\
				ft_strupper.c

PRINT_FILE	=	ft_putchar.c							\
				ft_putstr.c								\
				ft_putendl.c							\
				ft_putnbr.c								\
				ft_putchar_fd.c							\
				ft_putstr_fd.c							\
				ft_putendl_fd.c							\
				ft_putnbr_fd.c							\
				ft_puttab.c								\
				ft_putnchar.c							\
				ft_putnofstr.c							\


STR_FILE	=	ft_skip_char.c							\
				ft_count_word.c							\
				ft_strlen_till.c						\
				ft_strrev.c								\
				ft_strlen.c								\
				ft_strdup.c								\
				ft_strcpy.c								\
				ft_strncpy.c							\
				ft_strcat.c								\
				ft_strncat.c							\
				ft_strlcat.c							\
				ft_strchr.c								\
				ft_strrchr.c							\
				ft_strstr.c								\
				ft_strnstr.c							\
				ft_strcmp.c								\
				ft_strncmp.c							\
				ft_strnew.c								\
				ft_strdel.c								\
				ft_strclr.c								\
				ft_striter.c							\
				ft_striteri.c							\
				ft_strmap.c								\
				ft_strmapi.c							\
				ft_strequ.c								\
				ft_strnequ.c							\
				ft_strsub.c								\
				ft_strjoin.c							\
				ft_strtrim.c							\
				ft_strsplit.c							\
				ft_strtrim_full.c							\
				ft_strmiam.c

FILE_FILE	=	get_next_line.c


##############
## INC FILE ##
##############

HEAD		=	libft.h


# ################
# ## Conversion ##
# ################

OBJ		=	$(SRC:.c=.o)

# ###########################
# ## Random Initialisation ##
# ###########################

CC		=	gcc -o

CFLAGS	=	-Wall -Wextra -Werror -I$(INC_PATH)

RM		=	rm -rf

# ######################
# ## Compilatin Rules ##
# ######################

all		: $(NAME)

color	: 
	@echo "\033[0;33mTest Colorlolol\033[0m"

lol		:
		gcc -c $(CFLAGS) $(SRC)
		@echo "MDR"

$(NAME)		: $(OBJ) $(INC)
			@echo "\033[0;33mLibrary < $(NAME) > Creation\033[0m"
			@ar rc $(NAME) $(OBJ)
			@ranlib $(NAME)
			@echo "\033[0;32mLibray < $(NAME) > Correctly Build\033[0m"

# ####################
# ## Cleaning Rules ##
# ####################

clean		:
			@$(RM) $(OBJ)
			@echo "\033[0;32mObject File Delete\033[0m"

fclean		: clean
			@$(RM) $(NAME)
			@echo "\033[0;32mBinary $(NAME) Delete\033[0m"

re		:	fclean $(NAME)

# ################
# ## Protection ##
# ################

.PHONY		:	re clean fclean