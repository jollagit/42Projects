/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:07:54 by gvigano           #+#    #+#             */
/*   Updated: 2024/05/08 21:06:40 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*sort_list(t_list *list)
{
	size_t	size;
	
	size = 0;
	if (size < 4)
	{
		if (size == 2)
			swap(list, 'a');
		else
			sort_three(list);
	}
	//sort-algoritm
	return (list);
}

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

	i = check_list_three(list);
	if (i == 0)
		list = rotate(list, 'a');
	else if (i == 1)
		list = reverse_rotate(list, 'a');
	if (list->content > list->next->content)
		list = swap(list, 'a');
	return (list);
}

t_list	*check_list(t_list *list)
{
	t_list	*current;

	current = list;
	while (current->next)
	{
		if (current->content > current->next->content)
		{
			sort_list(list);
			break ;
		}
		current = current->next;
	}
	return (list);
}




