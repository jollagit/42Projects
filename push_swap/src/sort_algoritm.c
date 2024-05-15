/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algoritm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:09:24 by gvigano           #+#    #+#             */
/*   Updated: 2024/05/15 13:45:06 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*search_max_min(int target, t_list *list_a)
{
	char	*maxmin;

	maxmin = NULL;
	while (list_a)
	{
		if (list_a->content > target)
		{
			if (list_a->content < ft_atoi(maxmin) || maxmin == NULL)
			{
				free (maxmin);
				maxmin = ft_itoa(list_a->content);
			}
		}
		list_a = list_a->next;
	}
	return (maxmin);
}

size_t	find_index(t_list *list, int target)
{
	size_t	index;

	index = 0;
	while (list->content != target)
	{
		list = list->next;
		index++;
	}
	return (index);
}

static void	push_chunk_b(t_list **list_a, t_list **list_b, int size)
{
	while (ft_lstsize(*list_a) > 3)
	{
		if ((*list_a)->content < (size / 4))
		{
			push(list_a, list_b, 'b');
			(*list_b) = rotate((*list_b), 'b');
		}
		else
			push(list_a, list_b, 'b');
	}
}

t_list	*sort_list(t_list *list_a, t_list *list_b)
{
	int	size;

	size = ft_lstsize(list_a);
	while (ft_lstsize(list_a) > (size / 2))
	{
		if (list_a->content < (size / 2) && list_a->content >= (size / 4))
		{
			push(&list_a, &list_b, 'b');
			list_b = rotate(list_b, 'b');
		}
		else if (list_a->content >= (size / 2)
			&& list_a->content < (size - (size / 4)))
			push(&list_a, &list_b, 'b');
		else
			list_a = rotate(list_a, 'a');
	}
	push_chunk_b(&list_a, &list_b, size);
	list_a = sort_three(list_a);
	list_a = sort_list_back(list_b, list_a);
	return (list_a);
}
