/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 18:38:47 by ccatoire          #+#    #+#             */
/*   Updated: 2018/05/20 18:38:50 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>

/*
** ###############
** #  STRUCTURE  #
** ###############
*/

typedef struct		s_node
{
	void			*data;
	size_t			data_size;
	struct s_node	*next;
	struct s_node	*back;
}					t_node;

typedef struct		s_list
{
	size_t			size;
	t_node			*node;
	t_node			*first;
	t_node			*last;
}					t_list;

/*
** ###############
** #  PROTOTYPE  #
** ###############
*/

/*
** list
*/

void				ft_lstadd_end(t_list *lst, t_node *node);
void				ft_lstadd_begin(t_list *lst, t_node *node);
void				ft_lstadd_at(t_list *lst, t_node *node, size_t n);
void				ft_lstinit(t_list *lst, t_node *node);
void				ft_lstswap(t_node *lst1, t_node *ls2);
void				ft_lstdelone(t_list *node, t_node **alst,
															void(*del)(void**));
void				ft_lstdel(t_list **alst, void(*del)(void**));
size_t				ft_lstlen(t_node *n);
t_list				*ft_lstsort(t_list *lst, int (*cmp)(t_node *, t_node *));
t_list				*ft_lstcat(t_list *dest, t_list *src);
t_list				*ft_lstncat(t_list *dest, t_list *src, size_t n);
t_list				*ft_lstsub(t_list *lst, size_t start, size_t len);
t_list				*ft_lstnew();
t_node				*ft_lstgetn(t_list *lst, size_t n);
t_node				*ft_nodegetn(t_node *node, size_t n);
t_node				*ft_lstnew_node_m(void *data, size_t data_size);
t_node				*ft_lstnew_node(const void *data, size_t data_size);

#endif
