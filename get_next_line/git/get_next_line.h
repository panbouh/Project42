/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 11:31:11 by ccatoire          #+#    #+#             */
/*   Updated: 2017/06/01 11:31:13 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE		(5)
# define RD_DONE		(1)
# define RD_END			(0)

# include "libft.h"
# include <sys/stat.h>
# include <fcntl.h>

int			get_next_line(int fd, char **line);


/* libft */
int			ft_tablen(const char **tab);
char		**ft_realloc(char **s, size_t size);
char		*str_miam(char *str, char stop);


#endif
