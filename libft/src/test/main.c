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

typedef struct	s_test
{
	char			*name;
	char			*age;
	char			*id;
}				t_test;

void	lstput(t_list *lst, const char *name)
{
	if (!lst)
	{
		ft_putendl("NULL");
		return ;
	}
	t_node	*node = lst->first;
	ft_printf("%s :\n", name);
	while (node)
	{
		ft_printf("%s->", ((t_test*)node->data)->name);
		node = node->next;
	}
	ft_putendl("NULL");
}

t_test	*new_test(int n)
{
	t_test	*new = malloc(sizeof(*new));
	ft_bzero(new, sizeof(*new));

	new->name = ft_itoa(n + 100);
	new->age = ft_itoa(n);
	new->id = ft_itoa(n + 1000);
	return (new);
}

void	del_test(void **bouh)
{
	t_test *del = *bouh;

	ft_strdel(&del->name);
	ft_strdel(&del->age);
	ft_strdel(&del->id);
}

int	sort_lol(t_node *n1, t_node *n2)
{
	if (ft_strcmp(((t_test *)n1->data)->name, ((t_test *)n2->data)->name) > 1)
		return (1);
	return (1);
}

void	test_print(t_node *lol)
{
	while (lol)
		ft_putstr(((t_test *)lol->data)->name);
}

t_list			*test_sort(t_list *lst, int (*cmp)(t_node *, t_node *));


int	main(int ac, char **av)
{
	t_list	*lst = ft_lstnew();

	t_test	*test;
	
	for (int i = 5; i > 0; i--)
	{
		test = new_test(i);
		ft_lstadd_end(lst, ft_lstnew_node(test, sizeof(*test)));
	}
	// lstput(lst, "lst");
	lst = test_sort(lst, &sort_lol);


	// lstput(lst, "lst sorted");

	// lstput(lst, "lst sorted");


	ft_lstdel(&lst, &ft_memdel);	

	return (1);
}
