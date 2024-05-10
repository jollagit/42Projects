/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:07:54 by gvigano           #+#    #+#             */
/*   Updated: 2024/05/10 16:26:00 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*sort_list(t_list *list_a, t_list *list_b)
{
	if (ft_lstsize(list_a) == 4)
		push(&list_a, &list_b, 'b');
	else if (ft_lstsize(list_a) > 4)
	{
		push(&list_a, &list_b, 'b');
		push(&list_a, &list_b, 'b');
	}
	while (ft_lstsize(list_a) > 3)
		push(&list_a, &list_b, 'b');
	//list_a = sort_three(list_a);
	sort_simulator(list_a, list_b);
	/*while (list_b)
		push(&list_b, &list_a, '0');//sort-back-algoritm*/
	print_list(list_a, list_b);
	return (list_a);
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

t_list	*check_list(t_list *list_a, t_list *list_b)
{
	t_list	*current;

	current = list_a;
	while (current->next)
	{
		if (current->content > current->next->content)
		{
			list_a = sort_list(list_a, list_b);
			break ;
		}
		current = current->next;
	}
	return (list_a);
}




