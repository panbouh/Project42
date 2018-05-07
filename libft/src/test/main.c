#include "libft.h"
#include "ft_list.h"
#include "ft_printf.h"
#include "limits.h"
#include "time.h"
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h>
#include <dirent.h>

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

int main(int ac, char **av)
{
	// char *bouh = "un deux trois mdr";
	// char **lol = ft_strsplit(bouh, ' ');
	// ft_printf("WTF\n");
	// // ft_tabdel((void**)lol);
	// while (2){}

	char **bouh = ft_strsplit("donc un il un home moche mdr", ' ');
	char *ntm = bouh[2];
	ft_printf("bouh[2]\t\t= %p\nntm\t\t= %p\n", bouh[2], ntm);
	ft_strdel(&ntm);
	ft_printf("bouh[2]\t\t= %p\nntm\t\t= %p\n", bouh[2], ntm);
	if (bouh[2])
		BOUH
	ft_tabsdel(bouh);
	return (0);
}


// int	main(int ac, char **av)
// {
// 	// char	*s1 = av[1];
// 	// char	*s2 = av[2];
// 	// ft_printf("res : %i\n", ft_strcmp(s1, s2));

// 	char	*s1	= "1";
// 	char	*s2	= "2";
// 	char	*s3	= "3";
// 	char	*s4	= "4";
// 	char	*s5	= "5";
// 	char	*s6	= "6";
// 	t_list	*lst = ft_lstnew();
// 	// t_list	*new = ft_lstnew();
// 	// t_list	*sub = NULL;
// 	ft_lstadd_end(lst, ft_lstnew_node(s1, sizeof(s1)));
// 	// ft_lstadd_end(lst, ft_lstnew_node(s2, sizeof(s2)));
// 	// ft_lstadd_end(lst, ft_lstnew_node(s3, sizeof(s3)));
// 	// ft_lstadd_end(lst, ft_lstnew_node(s4, sizeof(s4)));
// 	// ft_lstadd_end(lst, ft_lstnew_node(s5, sizeof(s5)));
// 	// ft_lstadd_end(lst, ft_lstnew_node(s6, sizeof(s6)));

// 	// lstput(lst, "lst avantcat");
// 	// lstput(sub, "sub");
// 	// lst = ft_lstcat(lst, lst2);
// 	// lstput(lst, "lst aprescat");
// 	// sub = ft_lstsub(lst, 1, 3);
// 	// lstput(sub, "sub");
// 	ft_printf("lst : %p\n", lst);
// 	// ft_lstdelone(lst, &lst->node);
// 	ft_lstdelone(lst, lst->node);
// 	ft_printf("lst : %p\n", lst);


// 	// ft_lstdel(&sub);
// 	return (1);
// }
