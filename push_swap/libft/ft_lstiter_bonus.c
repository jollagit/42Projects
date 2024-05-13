/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:57:37 by gvigano           #+#    #+#             */
/*   Updated: 2024/05/13 17:16:21 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(int))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*void	ft_printlist(void *element)
{
	printf("%s ", (char *)element);
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
	printf("adesso la lista e':");
	ft_lstiter(lista, ft_printlist);
	return (0);
}*/

/*Description: Iterates the list ’lst’ and applies the function
’f’ on the content of each node.
Return Value: None*/