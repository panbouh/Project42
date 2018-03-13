#
#

PATHMY	=	./my_mlx/

LIBFT_INC	=	../libft/includes/

NOM		=	libmlx.a
SRC		=	mlx_shaders.c						\
			mlx_new_window.m					\
			mlx_init_loop.m						\
			mlx_new_image.m						\
			mlx_xpm.c							\
			mlx_int_str_to_wordtab.c			\
			$(PATHMY)mlx_put_line.c				\
			$(PATHMY)mlx_put_line_img.c				\
			$(PATHMY)mlx_pix_put_img.c			\
			$(PATHMY)mlx_init_my.c

OBJ1	=	$(SRC:.c=.o)
OBJ		=	$(OBJ1:.m=.o)
CFLAGS	+=	-O2 -I $(LIBFT_INC)

all: $(NOM)

$(NOM): $(OBJ)
	ar -r $(NOM) $(OBJ)
	ranlib $(NOM)

clean:
	rm -f $(NOM) $(OBJ) *~
	rm -f mlx_app

re: clean all
