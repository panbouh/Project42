/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikeita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 02:35:12 by nikeita           #+#    #+#             */
/*   Updated: 2017/03/19 03:37:09 by nikeita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


int		probleme_ligne(int **tab, int x, int y)
{
	int i = 0;
	int j = 0;
	int somme = 0;
	while (i < x)
	{
		j = 0;
		somme = 0;
		while(j < y)
		{
			somme = somme + tab[i][j];
			j++;
		}
		printf("somme de cette ligne : %d\n", somme);
		if (somme != 45)
			return (i);
		i++;
	}
	return (-1);
}


void	ft_sort_integer_table(int *tab, int size)
{
	int k;
	int tempo_var;
	int l;

	k = 0;
	tempo_var = 0;
	l = 0;
	while (k < size)
	{
		l = 0;
		while (l < size)
		{
			if (tab[l] > tab[l + 1] && ((l + 1) != size))
			{
				tempo_var = tab[l];
				tab[l] = tab[l + 1];
				tab[l + 1] = tempo_var;
			}
			l++;
		}
		k++;
	}
}

void	pas_de_zero(int **tab, int x, int y)
{
	int i;
	int j;

		i = 0;
		j = 0;
		while (i < x)
		{
			j = 0;
			while(j < y)
			{
				if (tab[i][j] == 10 || tab[i][j] == 0)
					tab[i][j] = 1;
				j++;
			}
			i++;
		}
}

void	afficher_tab(int **tab, int x, int y)
{
	int j;
	int i;

	i = 0;
	j = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			if (j == y-1)
				printf("%d", tab[i][j]);
			else
				printf("%d ", tab[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}

int		**initiali_tab_a_0(int **tab, int x, int y)
{
	int i;
	int j;
	int p = 0;

	i = 0;
	j = 0;

	while( p < 2)
	{
		while (i < x)
		{
			j = 0;
			while (j < y)
			{
				tab[i][j] = 0;
				j++;
			}
			i++;
		}
		p++;
	}

	return (tab);
}

int	total(int **tab, int x, int y)
{
	int i;
	int j;
	int somme;
	int sommetotal;

	i = 0;
	j = 0;
	somme = 0;
	sommetotal = 0;
	while (i < x)
	{
		somme = 0;
		j = 0;
		while(j < y)
		{
			somme = somme + tab[i][j];
			j++;
		}
		i++;
		sommetotal = sommetotal + somme;
	}
		//printf("La somme totale de ce tab est %d\n", sommetotal);
	return (sommetotal);
}


