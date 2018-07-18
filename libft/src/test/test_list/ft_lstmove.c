void	ft_lstmove_beg(t_list *dest, t_node *src, size_t n)
{

}

void	ft_lstmove_end(t_list *dest, t_node *src, size_t n)
{

}

void	ft_lstmove(t_list *dest, t_node *src, size_t n)
{
	t_node *curr;
	t_node *prev;
	t_node *front;

	if (n == 0)
		ft_lstmove_beg(dest, src);
	else if (n >= dest->size)
		ft_lstmove_end(dest, src);
	else
	{
		curr = ft_lstgetn(dest, n);
		prev = src->back;
		front = src->next;
		if (curr == src)
			return ;
		prev->next = front;
		front->back = prev;
		src->next = NULL;
		src->back = NULL;
		dest->size--;
		ft_lstadd_at(dest, src, n);
	}
}