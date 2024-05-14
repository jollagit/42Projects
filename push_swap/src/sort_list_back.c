/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:15:04 by gvigano           #+#    #+#             */
/*   Updated: 2024/05/13 19:52:38 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_r(t_list **lb, t_list **la, char *maxmin, int target)
{
	size_t	index[2];
	size_t	size_a;
	size_t	size;

	get_size(*la, *lb, &size_a, &size);
	index[0] = find_index((*lb), target);
	index[1] = 0;
	if (maxmin)
		index[1] = find_index((*la), ft_atoi(maxmin));
	while ((*lb)->content != target
		|| (maxmin && (*la)->content != ft_atoi(maxmin)))
	{
		if ((*lb)->content != target && index[0] <= (size / 2)
			&& index[0] != 0)
			(*lb) = rotate((*lb), 'b');
		else if ((*lb)->content != target && index[0] > (size / 2)
			&& index[0] != size)
			(*lb) = reverse_rotate((*lb), 'b');
		else if (maxmin && ((*la)->content != ft_atoi(maxmin)
				&& index[1] <= (size_a / 2)))
			(*la) = rotate((*la), 'a');
		else if (maxmin && ((*la)->content != ft_atoi(maxmin)
				&& index[1] > (size_a / 2)))
			(*la) = reverse_rotate((*la), 'a');
	}
}

static void	do_rr(t_list **lb, t_list **la, char *maxmin, int target)
{
	size_t	index_a;
	size_t	index_b;
	size_t	size_a;
	size_t	size_b;

	size_b = ft_lstsize((*lb));
	size_a = ft_lstsize((*la));
	index_b = find_index((*lb), target);
	index_a = find_index((*la), ft_atoi(maxmin));
	while ((*lb)->content != target && (*la)->content != ft_atoi(maxmin))
	{
		if ((index_b > (size_b / 2) && index_a > (size_a / 2))
			|| (index_b > (size_b / 2) && (index_a + 1) == size_a))
		{
			(*la) = reverse_rotate((*la), '0');
			(*lb) = reverse_rotate((*lb), 'r');
		}
		else if (index_b <= (size_b / 2) && index_a <= (size_a / 2))
		{
			(*la) = rotate((*la), '0');
			(*lb) = rotate((*lb), 'r');
		}
		else
			break ;
	}
}

static t_list	*sort_list_a(t_list *list_a, size_t size)
{
	t_list	*current;
	int		min;
	size_t	index;

	min = INT_MAX;
	current = list_a;
	while (current)
	{
		if (current->content < min)
			min = current->content;
		current = current->next;
	}
	index = find_index(list_a, min);
	while (list_a->content != min)
	{
		if (index > (size / 2) || index == (size - 1))
			list_a = reverse_rotate(list_a, 'a');
		else
			list_a = rotate(list_a, 'a');
	}
	return (list_a);
}

t_list	*sort_list_back(t_list *list_b, t_list *list_a)
{
	int		bestnum;
	char	*maxmin;

	maxmin = NULL;
	while (ft_lstsize(list_b) > 0)
	{
		bestnum = sort_back_simulator(list_b, list_a);
		maxmin = search_max_min(bestnum, list_a);
		if (maxmin)
			do_rr(&list_b, &list_a, maxmin, bestnum);
		else
			list_a = sort_list_a(list_a, ft_lstsize(list_a));
		do_r(&list_b, &list_a, maxmin, bestnum);
		push(&list_b, &list_a, 'a');
		free (maxmin);
	}
	return (list_a);
}
