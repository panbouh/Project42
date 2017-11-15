/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 13:09:18 by tlernoul          #+#    #+#             */
/*   Updated: 2017/09/19 15:35:33 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H
# define BUFFMAX_O	122
# define BUFFMAX_I	547
# define FALSE		-42
# define TRUE		42
# define NOPE		69
# define TABSIZE	13
# define ERR		87
# define USE		123

# include <string.h>
# include <unistd.h>
# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_tlist
{
	char			letter;
	char			*tetri;
	struct s_tlist	*next;
}					t_tlist;

typedef struct		s_pos
{
	int				x;
	int				y;
	int				s;
}					t_pos;

int					ft_putpiece(char grid[][13], t_pos *pos, t_tlist elem);
int					ft_placetet(t_tlist *tetlist);
int					ft_check_n_put(char grid[][13], t_pos *pos, t_tlist elem);
int					ft_check_place(char grid[][13], t_pos *pos, t_tlist elem);
int					tryfit(t_pos pos, char str[][TABSIZE], t_tlist *elem);
int					fillit_square(char *str);
int					firstalloc(t_tlist *elem);
int					check_sharp(char *str, char c);
char				*ft_checkshape(char *str);
char				*ft_buffer(char *pth);
char				*ft_buffer(char *pth);
t_tlist				*ft_lstetnew(char letter, char *tetri);
t_tlist				*ft_reader(char *str);
t_tlist				*fillit_chkshp(char *str);
t_pos				get_pos(char str[][TABSIZE], char letter, int size);
void				remove_t(char str[][13], char letter, int size);
void				reset_pos(t_pos *pos);
void				set_map(char str[][TABSIZE]);
void				print_map(char dbug[][TABSIZE], t_pos *p);
void				clafaim(char str[][TABSIZE], t_pos *p);
void				print_use(int i);

#endif
