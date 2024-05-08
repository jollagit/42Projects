/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliaviga <giuliaviga@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:04:02 by gvigano           #+#    #+#             */
/*   Updated: 2024/04/24 18:30:57 by giuliaviga       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(int))
{
	if (!lst)
		return ;
	if (del != NULL)
		del(lst->content);
	free(lst);
}
/*void	ft_printlist(t_list *list)
{
	t_list	*current = list;
	while(current != NULL)
	{
		printf("%s ", (char *)(current->content));
		current = current->next;
	}
}

t_list	*ft_newelem(void *newel)
{
	t_list	*element;

	element = (t_list *)malloc(sizeof(t_list));
	if(!element)
		return(NULL);
	if (newel)
		element->content = strdup((char *)newel);// duplico la stringa
	else
		element->content = NULL;
	element->next = NULL;
	return (element);
}
int	main(int argc, char *argv[])
{
	t_list	*newel;
	t_list	*lista;
	t_list	*temp;
	
	if (argc != 3)
		return (0);
	lista = NULL;
	newel = ft_newelem(argv[1]);
	ft_lstadd_front(&lista, newel);
	newel = ft_newelem(argv[2]);
	ft_lstadd_front(&lista, newel);
	printf("lista:");
	ft_printlist(lista);
	temp = lista;
	lista = temp->next;
	ft_lstdelone(temp, ft_delete);
	printf("\n adesso la lista e':");
	ft_printlist(lista);
	return (0);
}*/

/*Description: Takes as a parameter a node and frees the memory of
the node’s content using the function ’del’ given
as a parameter and free the node. The memory of
’next’ must not be freed.
Return Value: None*/