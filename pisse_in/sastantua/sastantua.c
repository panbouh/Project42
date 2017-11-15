/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 18:18:08 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/12 18:43:17 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putnchar(char c, int n)
{
	while (n != 0)
	{
		ft_putchar(c);
		n--;
	}
}

void	sastantua(int size)
{
	while (42)
		ft_putnchar('4', 2);
}
