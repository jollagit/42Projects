/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:07:43 by gvigano           #+#    #+#             */
/*   Updated: 2024/05/03 12:15:54 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	if (!list || list->next == NULL)
		return (list);
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
	t_list	*new_tail;
	t_list	*current;
	t_list	*new_head;

	if (!*list || (*list)->next == NULL)
		return ;
	current = *list;
	new_tail = NULL;
	new_head = NULL;
	while (current->next != NULL)
	{
		if (current->next->next == NULL)
			new_tail = current;
		current = current->next;
	}
	if (!new_tail)
		return ;
	new_head = new_tail->next;
	new_tail->next = NULL;
	current = new_head;
	while (current->next != NULL)
		current = current->next;
	current->next = *list;
	*list = new_head;
	return ;
}
