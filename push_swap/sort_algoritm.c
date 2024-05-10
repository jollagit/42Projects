/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algoritm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:09:24 by gvigano           #+#    #+#             */
/*   Updated: 2024/05/10 17:01:45 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*search_min_max(int content, t_list *list_b)
{
	char	*minmax;
	
	minmax = NULL;
	while (list_b)
	{
		if (list_b->content < content)
		{
			if (ft_itoa(list_b->content) > minmax || minmax == NULL)
				minmax = ft_itoa(list_b->content);
		}
		list_b = list_b->next;
	}
	return (minmax);
}

/*static size_t	num_moves(t_list *list_a, t_list *list_b, int min_max)
{
	
}*/

void	sort_simulator(t_list *list_a, t_list *list_b)
{
	t_list	*current;
	char	*min_max;
	int		best_num;
	size_t	less_moves;
	
	current = list_a;
	while (current)
	{
		min_max = search_min_max(current->content, list_b);
		if (less_moves > num_moves(list_a, list_b, min_max) || less_moves == 0)
		{
			less_moves = num_moves(list_a, list_b, min_max);
			best_num = current->content;
		}
		//ft_printf("%s\n", min_max);
		current = current->next;
	}
}
