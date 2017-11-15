/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:19:33 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/22 15:29:15 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

void	ft_print_words_tables(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		print(tab[i]);
		print("\n");
		i++;
	}
}
