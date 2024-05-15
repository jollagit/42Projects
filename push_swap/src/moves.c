/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:07:43 by gvigano           #+#    #+#             */
/*   Updated: 2024/05/13 21:36:03 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*swap(t_list *list, char c)
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
	if (c != '0')
		ft_printf("s%c\n", c);
	return (list);
}

void	push(t_list **list1, t_list **list2, char c)
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
	if (c != '0')
		ft_printf("p%c\n", c);
}

t_list	*rotate(t_list *list, char c)
{
	t_list	*current;
	int		tmp;
	t_list	*head;

	if (!list || list->next == NULL)
		return (list);
	head = list;
	tmp = list->content;
	current = list->next;
	while (current->next != NULL)
	{
		list->content = current->content;
		current = current->next;
		list = list->next;
	}
	list->content = current->content;
	list = list->next;
	list->content = tmp;
	list = head;
	if (c != '0')
		ft_printf("r%c\n", c);
	return (list);
}

t_list	*reverse_rotate(t_list *list, char c)
{
	t_list	*current;
	t_list	*new_head;

	if (!list || list->next == NULL)
		return (list);
	current = ft_lstlast(list);
	new_head = ft_lstnew(current->content);
	if (!new_head)
		return (list);
	ft_lstadd_front(&list, new_head);
	current = list;
	while (current->next->next)
		current = current->next;
	free(current->next);
	current->next = NULL;
	if (c != '0')
		ft_printf("rr%c\n", c);
	return (list);
}
