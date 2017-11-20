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
	void	(*f)(va_list);
}				t_bouh;

void	flag_int(va_list ap);
void	flag_char(va_list ap);
void	flag_str(va_list ap);



int	ft_printf(const char *format, ...);

#endif
