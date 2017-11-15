/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle-1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikeita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 13:46:06 by nikeita           #+#    #+#             */
/*   Updated: 2017/03/19 07:17:47 by nikeita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "lib.h"

int		check_doublenbr_line(int *tab, int x, int y)
{
	int i;
	int j;
	int *tab_tmp;

	tab_tmp = malloc(sizeof(int) * 9);

	i = 0;
	j = 0;
	while (i < x)
	{
		j = 0;
		while(j < y)
		{
			tab_tmp[j] = tab[j];
			j++;
		}
		i++;
	}
	ft_sort_integer_table(tab_tmp, 9);
	i = 0;
	j = 0;
	while (i < x)
	{
		j = 0;
		while(j < y)
		{
			if (tab_tmp[j] == tab_tmp[j-1])
				return 0;
			j++;
		}
		i++;
	}
	return (1);
}

int		*choperlescollones(int **tab,int x, int y)
{
	int *tab_tmp2;
	int i;

	i = 0;
	tab_tmp2 = (int *)malloc(sizeof(int) * (9));
	while(i < y)
	{
		tab_tmp2[i] = tab[i][x];
		i++;
	}
	//	free(tab_tmp2);
	//	printf("Lis tu cette ligne ?");
	return tab_tmp2;
}



int		check_lines(int **tab, int x, int y)
{
	int i;
	int j;
	int somme;
	int line_45;
	int Y;
	//	int stop = 0;

	Y = 0;
	i = 0;
	j = 0;
	somme = 0;
	line_45 = 0;

	while (i < x)
	{
		somme = 0;
		j = 0;
		while(j < y)
		{
			somme = somme + tab[i][j];
			j++;
		}
		//	while (Y < y)
		//	{
		//	printf("le result de checkdouble nbr_line est %d\n", check_doublenbr_line(tab[i], x, y) );
		//	if (!check_doublenbr_line(tab[i], x, y))
		//		stop = 1;
		//	if (somme == 45 && total(tab, x, y) &&  check_doublenbr_line(tab[i], x, y) != 0 /*  && (check_doublenbr_line(choperlescollones(tab, 1, y), x, y) != 0) */)
		//		line_45++;
		//	printf("TESTTRIIERFEIFE");
		//		Y++;
		//	}
		i++;
		//	printf("%d : Valeur de line_45\n", line_45);
	}
	/*
	   if (line_45 >= 7  && total(tab, 9, 9) && stop == 0)
	   {
	   printf("Valeur sommetotale : %d\n", total(tab, 9, 9));
	   printf("J AI TROUVE ENFIN PUTIN DE MERDE\n");
	   return (1);
	   }
	   else
	   return (0);
	   */
	return(0);
}

int		somme_d_une_ligne(int **tab, int x, int y, int ligne)
{
	int i = ligne;
	int j = 0;
	int somme = 0;
	while (i < x)
	{
		j = 0;
		while(j < y)
		{
			j++;
			somme = somme + tab[i][j];
		}
		return (somme);
		i++;
	}
	return (-1);
}


void		addone(int **tab, int ligne_a_prob, int colone_a_probl)
{
	tab[ligne_a_prob][colone_a_probl] = tab[ligne_a_prob][colone_a_probl] + 1;
	if (tab[ligne_a_prob][colone_a_probl] == 0 || tab[ligne_a_prob][colone_a_probl] == 10)
		tab[ligne_a_prob][colone_a_probl] = 1;
	//	printf("%d valeur\n", tab[ligne_a_prob][colone_a_probl]); 
}

int		 absentSurLigne (int k, int **tab, int i)
{
	for (int j=0; j < 9; j++)
		if (tab[i][j] == k)
			return 0;
	return 1;
}


int main(int argc, char **argv)
{
	int i;
	int j;
	int n;
	int k;
	char **u = argv;
	u = 0;
	/* Verification aue l utilisateur entre bien des chiffres ou des points */

	i = 1;
	j = 0;
	while(i <= 9)
	{
		j = 0;
		while (j < 9)
		{
			if ((argv[i][j] > 57 || argv[i][j] < 49) && argv[i][j] != '.')
			{
				printf("parametre bizzare");
				write(1, "Error", 5);
				write(1, "\n", 1);
				return (0);
			}
			j++;
		}
		i++;
	}


	/* Declaration du tab[][] avec malloc */
	i = 0;
	int **tab = (int **)malloc(9 * sizeof(int*));
	while (i < 9)
	{
		tab[i] = (int *)malloc(sizeof(int) * 9);
		i++;
	}
	initiali_tab_a_0(tab, 9, 9);
	// Affichage du tab rempli de 0
	afficher_tab(tab,9,9);
	printf(" ----- FIN DU TAB -----\n");

	j = 0;
	i = 1;
	n = 0;
	k = 0;
	if (argc == 10)
	{
		while (i < argc)
		{
			j = 0;
			k = 0;
			while(j < 9)
			{
				tab[n][k] = argv[i][j] - 48;
				j++;
				k++;
			}
			i++;
			n++;
		}
	}
	else
	{
		printf("VOUS n avez pas entrer 9 parametre");
		write(1, "Error", 5);
		write(1, "\n", 1);
	}

	//	pas_de_zero(tab,9, 9);

	j = 0;
	k = 0;
	i = 0;

	while (i < 9)
	{
		j = 0;
		k = 0;
		while(j < 9)
		{
			if (argv[i][j] == '.')
			{
				tab[i][j] = 0;

			//	tab[i][j] = tab[i][j] + 1;
			//	printf("%d une fois\n", tab[i][j]);
			//	printf("%d Valeur rechercher\n", absentSurLigne(tab[i][j], tab, i));
		//		while (absentSurLigne(tab[i][j], tab, i) == 0  && somme_d_une_ligne(tab, 9, 9, i) != 45)
				{
				//	printf("%d Valeur rechercher\n", absentSurLigne(tab[i][j], tab, i));

				//	printf("%d une fois\n", tab[i][j]);
		//			tab[i][j] = tab[i][j] + 1;
				}
			}
			//			while (!absentSurLigne(tab[i][j], tab, i))
			//			addone(tab, i, j);
			//pas_de_zero(tab, 9, 9);
			j++;
			k++;
		}
		i++;
		n++;
	}


	/*
	   if (probleme_ligne(tab, 9, 9) != -1)
	   addone(tab, 9, 9, probleme_ligne(tab, 9, 9), );
	   pas_de_zero(tab, 9, 9);
	   */

	//	estValide(tab, 0, 9 , 9);
	afficher_tab(tab, 9, 9);

	return(0);
}
