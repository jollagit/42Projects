/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliaviga <giuliaviga@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:21:28 by gvigano           #+#    #+#             */
/*   Updated: 2024/04/23 19:43:09 by giuliaviga       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list	*lstnew;
	int		fu;
	t_list	*element;

	if (!lst || !f || !del)
		return (NULL);
	lstnew = NULL;
	while (lst)
	{
		fu = f(lst->content);
		element = ft_lstnew(fu);
		if (!element)
		{
			ft_lstclear(&lstnew, del);
			del(fu);
			return (NULL);
		}
		ft_lstadd_back(&lstnew, element);
		lst = lst->next;
	}
	return (lstnew);
}
/*void	*ft_printlist(void *element)
{
	printf("%s ", (char *)element);
	return (element);
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
void	ft_delete(void *element)
{
	if(element) //solo se e' stata corettamente allocata
		free(element);
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
	printf("adesso la lista e':");
	ft_lstmap(lista, ft_printlist, ft_delete);
	return (0);
}*/

/*Description: Iterates the list ’lst’ and applies the function
’f’ on the content of each node. Creates a new
list resulting of the successive applications of
the function ’f’. The ’del’ function is used to
delete the content of a node if needed.
Return Value: The new list.
NULL if the allocation fails.*/