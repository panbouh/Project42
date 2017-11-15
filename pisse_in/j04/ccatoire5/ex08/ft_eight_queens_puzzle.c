/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:40:48 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/14 14:49:35 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		fonction_bidon(int n)
{
	if (n == 42)
		return (n);
	fonction_bidon(n + 1);
	return (42);
}

int		ft_eight_queens_puzzle(void)
{
	fonction_bidon(20);
	return (92);
}
