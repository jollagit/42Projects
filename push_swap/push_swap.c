/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_algoritm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:15:57 by gvigano           #+#    #+#             */
/*   Updated: 2024/05/13 19:11:29 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*sort_array(int *array, size_t size)
{
	int		tmp;
	size_t	i;

	i = 0;
	while (i < (size - 1))
	{
		i++;
		if (array[i - 1] > array[i])
		{
			tmp = array[i];
			array[i] = array[i - 1];
			array[i - 1] = tmp;
			i = 0;
		}
	}
	return (array);
}

static int	*array_sorted(t_list *list, size_t size)
{
	int		*array;
	size_t	i;

	i = 0;
	array = ft_calloc((size + 1), sizeof(int));
	if (!array)
		return (0);
	while (list)
	{
		array[i] = list->content;
		list = list->next;
		i++;
	}
	array = sort_array(array, size);
	return (array);
}

static void	sort_final(t_list *list_a, int *min, size_t *min_index)
{
	size_t	i;
	t_list	*current;

	*min = INT_MAX;
	*min_index = 0;
	current = list_a;
	i = 0;
	while (current)
	{
		if (current->content < *min)
		{
			*min = current->content;
			*min_index = i;
		}
		current = current->next;
		i++;
	}
}

static t_list	*get_index(t_list *list, int *array, size_t size)
{
	t_list	*current;
	size_t	i;

	current = list;
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (array[i] == current->content)
			{
				current->content = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
	return (list);
}

t_list	*push_swap(t_list *list_a, t_list *list_b)
{
	int		*array;
	size_t	size;
	int		min;
	size_t	min_index;

	if (check_list(&list_a))
		return (list_a);
	size = ft_lstsize(list_a);
	array = array_sorted(list_a, size);
	list_a = get_index(list_a, array, size);
	list_a = sort_list(list_a, list_b);
	if (!check_list(&list_a))
	{
		sort_final(list_a, &min, &min_index);
		while (list_a->content != min)
		{
			if (min_index > (size / 2) || min_index == (size - 1))
				list_a = reverse_rotate(list_a, 'a');
			else
				list_a = rotate(list_a, 'a');
		}
	}
	free(array);
	return (list_a);
}
