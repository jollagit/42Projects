/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_back_sim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:15:12 by gvigano           #+#    #+#             */
/*   Updated: 2024/05/13 19:14:42 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	moves_r(size_t index_a, size_t index_b, size_t sa, size_t sb)
{
	size_t	nmoves;

	nmoves = 0;
	while ((index_a > 0 && index_a != sa) || (index_b > 0 && index_b != sb))
	{
		if (index_a <= (sa / 2) && index_a != 0)
			index_a--;
		else if (index_a > (sa / 2) && index_a != sa)
			index_a++;
		else if (index_b <= (sb / 2))
			index_b--;
		else if (index_b > (sb / 2))
			index_b++;
		nmoves++;
	}
	return (nmoves);
}

static size_t	moves_rr(size_t *index_a, size_t *index_b, size_t sa, size_t sb)
{
	size_t	nmoves;

	nmoves = 0;
	while ((*index_a > 0 && *index_b > 0)
		&& (*index_a != sa && *index_b != sb))
	{
		if ((*index_a > (sa / 2) && *index_b > (sb / 2))
			|| (*index_a >= (sa / 2) && (*index_b + 1) == sb))
		{
			(*index_a)++;
			(*index_b)++;
		}
		else if (*index_a <= (sa / 2) && *index_b <= (sb / 2))
		{
			(*index_a)--;
			(*index_b)--;
		}
		else
			break ;
		nmoves++;
	}
	return (nmoves);
}

static size_t	sort_a_sim(t_list *list_a, size_t size)
{
	t_list	*current;
	int		min;
	size_t	index;
	size_t	nmoves;

	min = INT_MAX;
	current = list_a;
	nmoves = 0;
	while (current)
	{
		if (current->content < min)
			min = current->content;
		current = current->next;
	}
	index = find_index(list_a, min);
	while (index > 0 && index != size)
	{
		if (index > (size / 2) || index == (size - 1))
			index++;
		else
			index--;
		nmoves++;
	}
	return (nmoves);
}

static size_t	num_moves(t_list *lb, t_list *la, char *maxmin, int target)
{
	size_t	nmoves;
	size_t	size_a;
	size_t	size_b;
	size_t	index_a;
	size_t	index_b;

	nmoves = 0;
	size_a = ft_lstsize(la);
	size_b = ft_lstsize(lb);
	index_b = find_index(lb, target);
	index_a = 0;
	if (maxmin)
	{
		index_a = find_index(la, ft_atoi(maxmin));
		nmoves = moves_rr(&index_a, &index_b, size_a, size_b);
	}
	else
		nmoves += sort_a_sim(la, ft_lstsize(la));
	nmoves += moves_r(index_a, index_b, size_a, size_b);
	return (nmoves);
}

int	sort_back_simulator(t_list *list_b, t_list *list_a)
{
	t_list	*head;
	char	*maxmin;
	size_t	nmoves;
	int		best_num;
	size_t	less_moves;

	less_moves = 0;
	best_num = 0;
	head = list_b;
	while (list_b)
	{
		nmoves = 1;
		maxmin = search_max_min(list_b->content, list_a);
		nmoves += num_moves(head, list_a, maxmin, list_b->content);
		free (maxmin);
		if (less_moves > nmoves || less_moves == 0)
		{
			less_moves = nmoves;
			best_num = list_b->content;
			if (less_moves == 1)
				break ;
		}
		list_b = list_b->next;
	}
	return (best_num);
}
