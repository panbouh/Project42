/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 11:37:38 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/14 12:10:35 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == '1')
		return (index);
	if (index >= 2)
		index = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	return (index);
}
