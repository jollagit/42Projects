/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_algoritm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:15:57 by gvigano           #+#    #+#             */
/*   Updated: 2024/05/05 22:00:33 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_array(t_list *list, int size)
{
	int	i;
	int	*array;

	i = 0;
	array = calloc(size, sizeof(int));
	if (!array)
		return ;
	while (i < size)
	{
		if (array[i] == '\0')
		{
			array[i] = list->content;
			list = list->next;
		}
		if (array[i] > list->content)
		{
			
		}
		i++;
	}
	return (array);
}

