/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:03:18 by ccatoire          #+#    #+#             */
/*   Updated: 2017/11/20 13:03:18 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_MLX_H
# define MY_MLX_H

/*
** Key input
*/
# define	KEY_ESC		53
# define	KEY_UP		126
# define	KEY_LEFT	123
# define	KEY_RIGHT	124
# define	KEY_DOWN	125
# define	KEY_SPACE	49
# define	KEY_TAB		48

typedef	struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct	s_line
{
	int		addx;
	int		addy;
	int		dx;
	int		dy;
	t_pos	p1;
	t_pos	p2;

}				t_line;

typedef	struct	s_env
{
	void		*mlx_p;
	void		*win_p;
	void		*img_p;
	char		*img_str;
	int			bpp;
	int			s_l;
	int			endian;
}				t_mlx_env;

/*
**	mlx_put_pix_img.c
*/
void	mlx_pix_put_img(char *img_str, int size, t_pos pos, unsigned int color);

/*
**	mlx_put_line.c
*/

void	mlx_put_line(t_mlx_env env, t_pos p1, t_pos p2, int color);
void	mlx_put_line_img(t_mlx_env env, t_pos p1, t_pos p2, int color);

/*
**	mlx_init.c
*/
t_line	mlx_init_line(const t_pos *p1, const t_pos *p2);

#endif
