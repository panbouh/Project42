/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:54:32 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/22 18:04:06 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

typedef enum	e_bool
{
	TRUE = 1,
	FALSE
}				t_bool;

# define EVEN(x)		(x % 2) == 0
# define EVEN_MSG 	"I have an even number of arguments.\n"
# define ODD_MSG		"I have an odd number of arguments.\n"
# define SUCCESS		0

#endif
