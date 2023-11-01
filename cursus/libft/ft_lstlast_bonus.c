/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:23:45 by gvigano           #+#    #+#             */
/*   Updated: 2023/11/01 16:28:07 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
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
	ft_printlist(lista);
	printf("\n l'ultimo elemento: %p", newel->content);
	return (0);
}*/

/*Description: Returns the last node of the list.
Return Value: Last node of the list*/