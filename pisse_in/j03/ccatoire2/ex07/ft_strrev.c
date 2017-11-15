/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 12:48:28 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/13 18:46:10 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_strrev(char *str)
{
	int		i;
	int		size;
	char	save;

	i = 0;
	size = ft_strlen(str);
	while (i < size / 2)
	{
		save = str[i];
		str[i] = str[(size - 1) - i];
		str[(size - 1) - i] = save;
		i++;
	}
	return (str);
}
