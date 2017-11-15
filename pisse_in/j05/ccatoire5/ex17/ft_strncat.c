/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 18:18:18 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/25 08:27:44 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char				*ft_strncat(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	y;

	i = 0;
	y = 0;
	while (dest[y])
		y++;
	while (src[i] && i < n)
	{
		dest[y] = src[i];
		i++;
		y++;
	}
	dest[y] = '\0';
	return (dest);
}
