/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:07:43 by gvigano           #+#    #+#             */
/*   Updated: 2024/05/08 21:54:53 by gvigano          ###   ########.fr       */
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
	ft_printf("p%c\n", c);
	return ;
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
	if (c != '0')
		ft_printf("r%c\n", c);
	list = head;
	return (list);
}

t_list	*reverse_rotate(t_list *list, char c)
{
	t_list	*current;
	t_list	*new_head;
	int		tmp;

	if (!list || list->next == NULL)
		return (list);
	while (current->next->next != NULL)
		current = current->next;
	new_head = current->next;
	current = list;
	while (current->next->next != NULL)
		current = current->next;
	current->next->next = list;
	current->next = NULL;
	list = new_head;
	if (c != '0')
		ft_printf("rr%c\n", c);
	return (list);
}

