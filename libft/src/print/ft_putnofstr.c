/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnofstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 18:21:03 by ccatoire          #+#    #+#             */
/*   Updated: 2018/05/20 18:21:03 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>

void	ft_putnofstr(const char *str, size_t n)
{
	size_t	i;
	size_t	size;

	i = 0;
	if ((size = ft_strlen(str)) < n)
		n = size;
	while (str[i] && i < n)
	{
		write(1, &str[i], 1);
		i++;
	}
}
