void	ft_lstdelone(t_list *lst, t_node **anode)
{
	t_node *tmp;

	if (!anode || !(*anode))
		return ;
	tmp = *anode;
	if (tmp->back)
		tmp->back->next = tmp->next;
	else
	{
		tmp->back = NULL;
		lst->first = tmp->next;
	}
	if (tmp->next)
		tmp->next->back = tmp->back;
	else
	{
		tmp->next = NULL;
		lst->last = tmp->back;
	}
	ft_memdel(&(*anode)->data);
	ft_memdel((void **)anode);
	if (!lst->node)
		*anode = lst->first;
}

void	ft_lstdelone(t_list *lst, t_node **anode)
{
	t_node *tmp;

	if (!anode || !(*anode))
		return ;
	tmp = *anode;

	ft_memdel(tmp->data);
	ft_memdel((void **)anode);

}
