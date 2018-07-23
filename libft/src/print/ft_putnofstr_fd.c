/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnofstr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 18:21:25 by ccatoire          #+#    #+#             */
/*   Updated: 2018/05/20 18:21:30 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>

void	ft_putnofstr_fd(const char *str, size_t n, int fd)
{
	size_t	i;
	size_t	size;

	i = 0;
	if ((size = ft_strlen(str)) < n)
		n = size;
	while (str[i] && i < n)
	{
		write(fd, &str[i], 1);
		i++;
	}
}
