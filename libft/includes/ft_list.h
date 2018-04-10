#ifndef	FT_LIST_H
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
void				ft_lstinit(t_list *lst, t_node *node);
void				ft_lstswap(t_node *lst1, t_node *ls2);
void				ft_lstdelone(t_list *node, t_node **alst);
void				ft_lstdel(t_list **alst);
// void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
// size_t				ft_lstsize(t_list *lst);
t_list				*ft_lstcat(t_list *dest, t_list *src);
t_list				*ft_lstsub(t_list *lst, size_t start, size_t len);
t_list				*ft_lstnew();
t_node				*ft_lstgetn(t_list *lst, size_t n);
t_node				*ft_lstnew_node(const void *data, size_t data_size);
// t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif