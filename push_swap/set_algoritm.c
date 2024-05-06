/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_algoritm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:15:57 by gvigano           #+#    #+#             */
/*   Updated: 2024/05/06 22:14:22 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*get_array(t_list *list, int *array, size_t size, size_t i)
{
	int	t;

	if ((array[i] == 0 && array[i + 1] == 0 && array[size + 1] == 0) || 
		(i != 0 && array[i] == 0 && array[i + 1] == 0)) 
	{
		array[i] = list->content;
		array[size + 1] = 1;
	}
	else if (array[i] > list->content)
	{
		t = 0;
		while ((size - t) > i)
		{
			array[size - t] = array[size - t - 1];
			t++;
		}
		array[i] = list->content;
	}
	return (array);
}

static int	*array_sorted(t_list *list, size_t size)
{
	int		*array;
	size_t	i;

	array = ft_calloc((size + 2), sizeof(int));
	if (!array)
		return (0);
	while (list)
	{
		i = 0;
		while (i < size)
		{
			array = get_array(list, array, size, i);
			if (array[i] == list->content)
				break ;
			i++;
		}
		list = list->next;
	}
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

t_list	*push_swap(t_list *list)
{
	int		*array;
	size_t	size;

	size = ft_lstsize(list);
	array = array_sorted(list, size);
	list = get_index(list, array, size);
	return (list);
}
