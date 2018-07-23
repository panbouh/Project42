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

int	sort_lol(t_node *n1, t_node *n2)
{
	if (ft_strcmp(n1->data, n2->data) > 0)
		return (1);
	return (0);
}

void	test_print(t_list *lst, char *name, char rev)
{
	ft_printf("%s :\n", name);
	if (!lst || !lst->first)
	{
		ft_printf("NULL\n");
		return ;
	}

	t_node	*lol;
	if (!rev)
	{
		lol = lst->first;
		while (lol)
		{
			ft_printf("%s->", lol->data);
			lol = lol->next;
		}
	}
	else
	{
		lol = lst->last;
		while (lol)
		{
			ft_printf("%s->", lol->data);
			lol = lol->back;
		}
	}
	ft_putchar('\n');
}

char	*new_test(int i)
{
	return (ft_itoa(i + 100));
}

t_list	*test_sort(t_list *lst, int (*cmp)(t_node*, t_node*));
void	ft_lstmove(t_list *dest, t_node *src, size_t n);

int	main(int ac, char **av)
{
	t_list	*lst = ft_lstnew();

	char	*test;
	
	for (int i = 5; i > 0; i--)
	{
		test = new_test(i);
		ft_lstadd_end(lst, ft_lstnew_node(test, sizeof(test)));
	}

	test_print(lst, "avant", 0);

	// lst = test_sort(lst, &sort_lol);

	char *bouh = new_test(42); //ft_lstnew_node(bouh, sizeof(bouh)), 1
	ft_lstmove(lst, ft_lstgetn(lst, 0), 5);
HR
	test_print(lst, "apres", 0);
	test_print(lst, "apres rev", 1);




	ft_lstdel(&lst, &ft_memdel);
	return (1);
}
