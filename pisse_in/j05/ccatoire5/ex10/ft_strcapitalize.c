/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_capitalize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:38:48 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/22 11:52:36 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int i_maj;

	i = 0;
	i_maj = 0;
	while (str[i])
	{
		i_maj = i;
		while ((str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= 'A' && str[i] <= 'Z')
				|| (str[i] >= '0' && str[i] <= '9'))
		{
			if (i == i_maj && str[i] >= 'a' && str[i] <= 'z')
				str[i_maj] -= 32;
			i++;
			if (i != i_maj && str[i] >= 'A' && str[i] <= 'Z')
				str[i] += 32;
		}
		i++;
	}
	return (str);
}
