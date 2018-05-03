#include "ft_ls.h"
#include "time.h"

int	sort_by_size(t_node *nd1, t_node *nd2)
{
	off_t	t1;
	off_t	t2;

	t1 = ((t_finfo*)nd1->data)->file_s.st_size;
	t2 = ((t_finfo*)nd2->data)->file_s.st_size;
	if (t1 < t2)
		return (1);
	return (0);
}

int	sort_by_ctime(t_node *nd1, t_node *nd2)
{
	time_t	t1;
	time_t	t2;

	t1 = ((t_finfo*)nd1->data)->file_s.st_ctime;
	t2 = ((t_finfo*)nd2->data)->file_s.st_ctime;
	if (t1 < t2)
		return (1);
	return (0);
}

int	sort_by_atime(t_node *nd1, t_node *nd2)
{
	time_t	t1;
	time_t	t2;

	t1 = ((t_finfo*)nd1->data)->file_s.st_atime;
	t2 = ((t_finfo*)nd2->data)->file_s.st_atime;
	if (t1 < t2)
		return (1);
	return (0);
}
