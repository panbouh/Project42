/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 18:28:52 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/16 14:25:07 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, int nb)
{
	int			i;
	int			y;

	i = 0;
	y = 0;
	while (dest[y])
		y++;
	while (src[i])
	{
		if (y < nb)
			dest[y] = src[i];
		i++;
		y++;
	}
	dest[y] = '\0';
	return (y);
}
