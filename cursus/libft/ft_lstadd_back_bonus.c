/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:27:10 by gvigano           #+#    #+#             */
/*   Updated: 2023/11/01 16:45:19 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*element;

	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	element = *lst;
	while (element->next != NULL)
		element = element->next;
	element->next = new;
}
/*void	ft_printlist(t_list *list)
{
	t_list	*current = list;
	while(current != NULL)
	{
		printf("%p ", current->content);
		current = current->next;
	}
}
int	main(int argc, char *argv[])
{
	t_list	*newel;
	t_list	*lista;
	
	if (argc != 3)
		return (0);
	lista = NULL;
	newel = ft_lstnew(argv[1]);
	ft_lstadd_front(&lista, newel);
	newel = ft_lstnew(argv[2]);
	ft_lstadd_back(&lista, newel);
	printf("lista:");
	ft_printlist(lista);
	return (0);
}*/

/*Description: Adds the node ’new’ at the end of the list.
Return Value: None*/