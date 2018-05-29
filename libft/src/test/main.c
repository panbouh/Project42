#include "libft.h"
#include "ft_list.h"
#include "ft_printf.h"
#include "limits.h"
#include "time.h"
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h>
#include <dirent.h>
#include <string.h>

void	lstput(t_list *lst, const char *name)
{
	if (!lst)
	{
		ft_putendl("NULL");
		return ;
	}
	t_node	*node = lst->node;
	ft_printf("%s :\n", name);
	while (node)
	{
		ft_printf("%s->", node->data);
		node = node->next;
	}
	ft_putendl("NULL");
}

int	lol(t_node *nd1, t_node *nd2)
{
	if ((ft_strcmp(nd1->data, nd2->data)) < 0)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	// char	*s1 = av[1];
	// char	*s2 = av[2];
	// ft_printf("res : %i\n", ft_strcmp(s1, s2));

	char	*s1	= "10000000";
	char	*s2	= "2213";
	char	*s3	= "313";
	char	*s4	= "423";
	char	*s5	= "521";
	char	*s6	= "643";
	t_list	*lst = ft_lstnew();

	ft_lstadd_end(lst, ft_lstnew_node(s6, sizeof(*s6) * ft_strlen(s6)));
	ft_lstadd_end(lst, ft_lstnew_node(s5, sizeof(*s5) * ft_strlen(s5)));
	ft_lstadd_end(lst, ft_lstnew_node(s4, sizeof(*s4) * ft_strlen(s4)));
	ft_lstadd_end(lst, ft_lstnew_node(s3, sizeof(*s3) * ft_strlen(s3)));
	ft_lstadd_end(lst, ft_lstnew_node(s2, sizeof(*s2) * ft_strlen(s2)));
	ft_lstadd_end(lst, ft_lstnew_node(s1, sizeof(*s1) * ft_strlen(s1)));

	lstput(lst, "pd");
	t_node	*lol = ft_lstgetn(lst, atoi(av[1]));
	ft_printf("je veux del : %s, qui a %p\n", lol->data, lol);
	ft_lstdelone(lst, &lol);

	lstput(lst, "pd");

	// ft_printf("avant : %p\n", lst);
	// lst = ft_lstsort(lst, &lol);
	// ft_printf("apres : %p\n", lst);



	// ft_lstdel(&lst);
	return (1);
}
