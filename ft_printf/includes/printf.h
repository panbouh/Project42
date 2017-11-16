/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:03:49 by ccatoire          #+#    #+#             */
/*   Updated: 2017/11/16 15:03:49 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "stdarg.h"

# define	FLAG_NB		4

typedef	struct	s_bouh
{
	char	key;
	void	(*f)(int);
}				t_bouh;

t_bouh	g_bouhtab[] = {
	{'i', &ft_putnbr},	\
	{'d', &ft_putnbr},	\
	{'s', &ft_putstr},	\
	{'c', &ft_putchar}

};

int	ft_printf(const char *format);

#endif
