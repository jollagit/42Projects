/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:21:28 by gvigano           #+#    #+#             */
/*   Updated: 2023/11/03 16:47:59 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstnew;
	t_list	*copy;

	if (!lst || !f || !del)
		return (NULL);
	lstnew = ft_lstnew(f(lst->content));
	if (!lstnew)
		return (NULL);
	copy = lstnew;
	lst = lst->next;
	while (lst)
	{
		lstnew->next = ft_lstnew(f(lst->content));
		if (!lstnew->next)
		{
			ft_lstclear(&copy, del);
			return (NULL);
		}
		lstnew = lstnew->next;
		lst = lst->next;
	}
	lstnew->next = NULL;
	return (copy);
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