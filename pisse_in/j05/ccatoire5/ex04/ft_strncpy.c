/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 19:24:11 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/29 12:16:58 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char					*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int		i;

	i = 0;
	if (n <= 0)
		return (dest);
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	while (dest[i])
		i++;
	dest[i] = '\0';
	return (dest);
}
