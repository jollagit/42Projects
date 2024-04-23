/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliaviga <giuliaviga@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:39:44 by gvigano           #+#    #+#             */
/*   Updated: 2024/04/23 19:37:53 by giuliaviga       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*next;

	if (lst == NULL || *lst == NULL)
		return ;
	while ((*lst) != NULL)
	{
		next = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = next;
	}
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
void	ft_delete(void *element)
{
	if(element) //solo se e' stata corettamente allocata
		free(element);
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
	
	if (argc != 4)
		return (0);
	lista = NULL;
	newel = ft_newelem(argv[1]);
	ft_lstadd_front(&lista, newel);
	newel = ft_newelem(argv[2]);
	ft_lstadd_front(&lista, newel);
	newel = ft_newelem(argv[3]);
	ft_lstadd_front(&lista, newel);
	printf("lista:");
	ft_printlist(lista);
	ft_lstclear(&lista, ft_delete);
	printf("\n adesso la lista e':");
	ft_printlist(lista);
	return (0);
}*/

/*Description: Deletes and frees the given node and every
successor of that node, using the function ’del’
and free(3).
Finally, the pointer to the list must be set to
NULL.
Return Value: None*/