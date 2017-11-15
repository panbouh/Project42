/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:04:46 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/16 19:31:51 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void		ft_takes_place(int hour)
{
	if (hour == 11)
		printf("THE FOLLOWING TAKES PLACE BETWEEN 11 A.M. AND 12 P.M.\n");
	else if (hour == 12)
		printf("THE FOLLOWING TAKES PLACE BETWEEN 12 P.M. AND 1 P.M.\n");
	else if (hour == 0)
		printf("THE FOLLOWING TAKES PLACE BETWEEN 12 A.M. AND 1 A.M.\n");
	else if (hour > 11)
		printf("THE FOLLOWING TAKES PLACE BETWEEN %i P.M. AND %i P.M.\n",
			hour - 12, hour - 11);
	else if (hour < 12)
		printf("THE FOLLOWING TAKES PLACE BETWEEN %i A.M. AND %i A.M.\n",
			hour, hour + 1);
	else if (hour == 23)
		printf("THE FOLLOWING TAKES PLACE BETWEEN 11 P.M. AND 12 A.M.\n");
}
