/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:07:54 by gvigano           #+#    #+#             */
/*   Updated: 2024/05/13 19:11:09 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	check_list_three(t_list *list)
{
	size_t	i;
	int		max;
	t_list	*current;

	i = 0;
	current = list;
	max = current->content;
	while (current)
	{
		if (max < current->content)
			max = current->content;
		current = current->next;
	}
	current = list;
	while (current->content != max)
	{
		i++;
		current = current->next;
	}
	return (i);
}

t_list	*sort_three(t_list *list)
{
	size_t	i;

	if (ft_lstsize(list) == 3)
	{
		i = check_list_three(list);
		if (i == 0)
			list = rotate(list, 'a');
		else if (i == 1)
			list = reverse_rotate(list, 'a');
	}
	if (list->content > list->next->content)
		list = swap(list, 'a');
	return (list);
}

int	check_list(t_list **list_a)
{
	t_list	*current;
	size_t	size;

	current = *list_a;
	size = ft_lstsize(*list_a);
	if (size <= 3)
		*list_a = sort_three(*list_a);
	while (current->next)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}
