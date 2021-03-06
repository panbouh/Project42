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
** init
*/
void				ft_lstdel(t_list **alst, void(*del)(void**));
void				ft_lstinit(t_list *lst, t_node *node);
t_list				*ft_lstnew();
t_node				*ft_lstnew_node_m(void *data, size_t data_size);
t_node				*ft_lstnew_node(const void *data, size_t data_size);

/*
** mod
*/
void				ft_lstadd_end(t_list *lst, t_node *node);
void				ft_lstadd_begin(t_list *lst, t_node *node);
void				ft_lstadd_at(t_list *lst, t_node *node, size_t n);
void				ft_lstswap(t_node *lst1, t_node *ls2);
void				ft_lstsort_ins(t_list *lst, int (*cmp)(t_node*, t_node*));
void				ft_lstmove(t_list *dest, t_node *src, size_t n);
void				ft_lstdelone(t_list *node, t_node **alst,
															void(*del)(void**));
t_list				*ft_lstcat(t_list *dest, t_list *src);
t_list				*ft_lstncat(t_list *dest, t_list *src, size_t n);
t_list				*ft_lstsub(t_list *lst, size_t start, size_t len);

/*
** convert
*/
char				**ft_lsttotab(t_list *lst);
char				**ft_lsttotab_m(t_list *lst);
t_list				*ft_lsttabsplit(char **tab);
t_list				*ft_lsttabsplit_m(char **tab);
t_list				*ft_lsttabsplit_t(char **tab);

/*
** read
*/
void				ft_lstput(t_list *lst, void (*put)(t_node));
void				ft_lstputstr(t_list *lst);
size_t				ft_lstlen(t_node *n);
t_node				*ft_lstgetn(t_list *lst, size_t n);
t_node				*ft_nodegetn(t_node *node, size_t n);
t_list				*ft_lstdup(t_list *lst);


#endif
