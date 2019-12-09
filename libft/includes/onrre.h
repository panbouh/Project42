/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onrre.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 00:16:56 by ccatoire          #+#    #+#             */
/*   Updated: 2019/07/28 00:16:57 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ONRRE_H
# define	ONRRE_H

/*
**	pourquoi ? onrre ben = errno a l'envers. <3
*/

# define	E_IDK			42
# define	E_IDK_STR		"i don't know why, good luck :)"

# define	E_NOPERM		-1
# define	E_NOPERM_STR	"permission denied"
# define	E_NOFOUND		-2
# define	E_NOFOUND_STR	"not found"
# define	E_NOTADIR		-3
# define	E_NOTADIR_STR	"not a directory"
# define	E_NOFILE		-4
# define	E_NOFILE_STR	"no such file or directory"

int	g_onrre;

typedef struct	s_onrre
{
	int		err_tag;
	char	*err_str;
}				t_onrre;

char	*get_onrre(int onrre);
char	*set_onrre_c(int onrre, char *ret);
int		set_onrre(int onrre, int ret);
int		put_onrre(char *s, int ret);

#endif
