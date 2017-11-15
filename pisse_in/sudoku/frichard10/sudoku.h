/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 11:02:50 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/19 16:05:21 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H

/*
** MACRO
*/

/*
** RETURN VALUE
*/
# define OK		(0)
# define ERROR		(-1)

/*
** OTHER
*/
# define VOID_PLACE	(' ')

/*
**  ---PROTOTYPE---
*/

/*
** MAIN.c
*/
int		check_grid(char **grid);
int		my_strlen(char *str);

/*
** FC_PRINT.c
*/
void	print(char c);
void	print_str(char *str);
void	print_grid(char **grid);

/*
** SUDOKU.c
*/
int		sudoku(char **grid);
int		check_line(char *line);
int		check_col(char **grid, int col);
int		check_block(char **grid, int y, int x);

#endif
