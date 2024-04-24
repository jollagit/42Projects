#include "push_swap.h"

t_list	*swap(t_list *list)
{
	t_list	*current;
	int		elem;

	if (!list || !list->next)
		return (list);
	current = list;
	current = current->next;
	elem = list->content;
	list->content = current->content;
	current->content = elem;
	return (list);
}

void	push(t_list **list1, t_list **list2)
{
	t_list	*current;
	t_list	*temp;

	if (!list1 || !*list1)
		return ;
	current = ft_lstnew((*list1)->content);
	if (!current)
		return ;
	ft_lstadd_front(list2, current);
	temp = *list1;
	*list1 = (*list1)->next;
	free (temp);
	return ;
}

