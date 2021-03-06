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
SRC_ONRRE	=	$(addprefix $(SRC_PATH),onrre/)
SRC_PRINT	=	$(addprefix $(SRC_PATH),print/)
SRC_STR		=	$(addprefix $(SRC_PATH),str/)
SRC_TAB		=	$(addprefix $(SRC_PATH),tab/)
SRC_FILE	=	$(addprefix $(SRC_PATH),file/)
SRC_PRINTF	=	$(addprefix $(SRC_PATH),printf/)
SRC_WSTR	=	$(addprefix $(SRC_PATH),wstr/)

#PATH MIXED
SRC		=	$(addprefix $(SRC_CHECK),$(CHECK_FILE))		\
			$(addprefix $(SRC_LIST),$(LIST_FILE))		\
			$(addprefix $(SRC_MATH),$(MATH_FILE))		\
			$(addprefix $(SRC_MEM),$(MEM_FILE))			\
			$(addprefix $(SRC_MORPH),$(MORPH_FILE))		\
			$(addprefix $(SRC_ONRRE),$(ONRRE_FILE))		\
			$(addprefix $(SRC_PRINT),$(PRINT_FILE))		\
			$(addprefix $(SRC_STR),$(STR_FILE))			\
			$(addprefix $(SRC_TAB),$(TAB_FILE))			\
			$(addprefix $(SRC_FILE),$(FILE_FILE))		\
			$(addprefix $(SRC_PRINTF),$(PRINTF_FILE))	\
			$(addprefix $(SRC_WSTR),$(WSTR_FILE))


INC		=	$(addprefix $(INC_PATH),$(HEAD))

##############
## SRC FILE ##
##############

CHECK_FILE	=	ft_isalpha.c							\
				ft_isdigit.c							\
				ft_isalnum.c							\
				ft_isascii.c							\
				ft_isprint.c							\
				ft_isvalid.c							\
				ft_isspace.c

FILE_FILE	=	get_next_line.c							\
				whats_my_file.c							\
				ft_access.c

LIST_FILE	=	ft_lstnew.c								\
				ft_lstadd.c								\
				ft_lstinit.c							\
				ft_lstgetn.c							\
				ft_lstswap.c							\
				ft_lstdelone.c							\
				ft_lstdel.c								\
				ft_lstcat.c								\
				ft_lstlen.c								\
				ft_lstsub.c								\
				ft_lstmove.c							\
				ft_lsttotab.c							\
				ft_lstdup.c								\
				ft_lsttabsplit.c						\
				ft_lstput.c								

MATH_FILE	=	ft_power.c								\
				ft_count_digit.c						\
				ft_count_digit_u.c						\
				ft_abs.c								\
				ft_conv_nbase.c							\
				ft_conv_fbase.c							\
				ft_addbit.c

MEM_FILE	=	ft_memset.c								\
				ft_bzero.c								\
				ft_memcpy.c								\
				ft_memccpy.c							\
				ft_memmove.c							\
				ft_memchr.c								\
				ft_memcmp.c								\
				ft_memswap.c							\
				ft_memalloc.c							\
				ft_memdup.c								\
				ft_memdel.c

MORPH_FILE	=	ft_atoi.c								\
				ft_itoa.c								\
				ft_toupper.c							\
				ft_tolower.c							\
				ft_strupper.c							\
				ft_strlower.c

ONRRE_FILE	=	get_onrre.c								\
				set_onrre.c								\
				put_onrre.c

PRINT_FILE	=	ft_putchar.c							\
				ft_putstr.c								\
				ft_putendl.c							\
				ft_putnbr.c								\
				ft_putchar_fd.c							\
				ft_putstr_fd.c							\
				ft_putendl_fd.c							\
				ft_putnbr_fd.c							\
				ft_puttab.c								\
				ft_putdtab.c							\
				ft_putstab.c							\
				ft_putnchar.c							\
				ft_putnofstr.c							\
				ft_putwchar.c							\
				ft_putwstr.c							\
				ft_error.c								\
				ft_putnofwstr.c

TAB_FILE	=	ft_tabcpy.c								\
				ft_tabnew.c								\
				ft_tabtskip.c							\
				ft_tabdup.c								\
				ft_tablen.c								\
				ft_tabschr.c							\
				ft_tabtchr.c							\
				ft_tabchr.c								\
				ft_tabdel.c

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
				ft_strtchr.c							\
				ft_strschr.c							\
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
				ft_strsub_to.c							\
				ft_strjoin.c							\
				ft_strtrim.c							\
				ft_strsplit.c							\
				ft_strtrim_full.c						\
				ft_strlen_c.c							\
				ft_strtotab.c							\
				ft_newpath.c							\
				ft_strmiam.c

WSTR_FILE	=	ft_wstrlen.c							\
				ft_wcharlen.c							\
				ft_putnbyte.c							\
				ft_wstrdup.c							\
				ft_wstrdel.c

PRINTF_FILE	=	ft_printf.c								\
				init.c									\
				flags.c									\
				calc.c									\
				err.c									\
				utils.c									\
				check_pw.c								\
				conv_uisc_z_ui.c						\
				conv_xop_z_id.c							\
				conv_l_scox.c							\
				conv_l_ui_h_ox.c						\
				conv_h_ui_ll_ox.c						\
				conv_ll_ui_hh_ox.c						\
				conv_hh_ui_j_ox.c						\
				conv_j_ui_z_ox.c						\
				conv_bonus_b.c							\
				conv_mod_jz.c							\
				conv_mod_lhllhh.c

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

CFLAGS	=	-Wall -Wextra -Werror -I$(INC_PATH) -g3

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