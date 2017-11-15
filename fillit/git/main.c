/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 12:24:32 by ccatoire          #+#    #+#             */
/*   Updated: 2017/09/15 12:24:32 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char *argv[])
{
	int			i;
	t_tlist		*elem;
	char		*str;

	i = 0;
	if (argc != 2)
	{
		print_use(USE);
		return (0);
	}
	if (!(str = ft_buffer(argv[1])))
	{
		print_use(ERR);
		return (0);
	}
	if ((elem = ft_reader(str)))
	{
		free(str);
		ft_placetet(elem);
	}
	print_use(ERR);
	return (0);
}
