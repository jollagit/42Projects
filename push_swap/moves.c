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

t_list	*rotate(t_list *list)
{
	t_list	*current;
	int		head;

	head = list->content;
	current = list->next;
	while (current->next != NULL)
	{
		list->content = current->content;
		current = current->next;
		list = list->next;
	}
	list->content = current->content;
	list = list->next;
	list->content = head;
	return (list);
}

void	reverse_rotate(t_list **list)
{
	int		tail;
	t_list	*current;
	t_list	*tmp;

	current = *list;
	while (current->next != NULL)
	{
		if (current->next->next == NULL)
		{
			tail = current->next->content;
			current->next = NULL;
		}
		current = current->next;
	}
	current = *list;
	tmp = *list;
	while (tmp->next != NULL)
	{		
		tmp = tmp->next;
		tmp->content = current->content;
		current = current->next;
	}
	return ;
}
