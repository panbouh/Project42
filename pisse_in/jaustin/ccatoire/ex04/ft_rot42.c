/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 12:10:14 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/17 13:49:18 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		if ((c >= 'a' && c < 'k') || (c >= 'A' && c < 'K'))
			return (1);
		else
			return (2);
	}
	else
		return (0);
}

char	*ft_rot42(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (is_alpha(str[i]) == 1)
			str[i] += 16;
		else if (is_alpha(str[i]) == 2)
			str[i] -= 10;
		i++;
	}
	return (str);
}
