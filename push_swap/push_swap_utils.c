/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:07:36 by gvigano           #+#    #+#             */
/*   Updated: 2024/05/03 16:14:35 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_list **list1, t_list **list2, char ***str)
{
	size_t	i;

	i = 0;
	if (list1 != NULL)
		ft_lstclear(list1);
	if (list2 != NULL)
		ft_lstclear(list2);
	while ((*str)[i])
		free((*str)[i++]);//ft_printf("Error");						
	free ((*str));
}

t_list	*fill_list(t_list *list,char **element)
{
	size_t	i;
	t_list	*new_element;

	if (!element)
		return (list);
	i = 0;
	while (element[i])
	{
		new_element = ft_lstnew(ft_atoi(element[i++]));
		ft_lstadd_back(&list, new_element);
	}
	return (list);
}

void	print_list(t_list *list_A, t_list *list_B)
{
	ft_printf("a)\tb)\n");
	while (list_A || list_B)
	{
		if (list_A)
		{
			ft_printf("%d\t", list_A->content);
			list_A = list_A->next;
		}
		else 
			ft_printf("\t");
		if (list_B)
		{
			ft_printf("%d\n", list_B->content);
			list_B = list_B->next;
		}
		else
			printf("\n");
	}
	return ;
}
