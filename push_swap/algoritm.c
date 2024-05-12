/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:07:54 by gvigano           #+#    #+#             */
/*   Updated: 2024/05/12 23:52:12 by menny            ###   ########.fr       */
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

int	check_list(t_list *list_a)
{
	t_list	*current;

	current = list_a;
	while (current->next)
	{
		if (current->content > current->next->content)
			return (0) ;
		current = current->next;
	}
	return (1);
}




