/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_algoritm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:15:57 by gvigano           #+#    #+#             */
/*   Updated: 2024/05/10 16:25:04 by gvigano          ###   ########.fr       */
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
				break;
			}
			i++;
		}
		current = current->next;
	}
	return (list);
}

t_list	*push_swap(t_list *list1, t_list *list2)
{
	int		*array;
	size_t	size;

	size = ft_lstsize(list1);
	array = array_sorted(list1, size);
	list1 = get_index(list1, array, size);
	list1 = check_list(list1, list2);
	free(array);
	return (list1);
}
