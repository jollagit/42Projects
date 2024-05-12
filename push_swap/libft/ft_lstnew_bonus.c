/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliaviga <giuliaviga@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:42:50 by gvigano           #+#    #+#             */
/*   Updated: 2024/04/23 19:37:07 by giuliaviga       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*element;

	element = (t_list *) malloc (sizeof(t_list));
	if (!element)
		return (NULL);
	element->content = content;
	element->next = NULL;
	return (element);
}
/*int	main(int argc, char *argv[])
{
	t_list	*newel;
	
	if (argc != 2)
		return (0);
	newel = ft_lstnew(argv[1]);
	printf("il nuovo elemento della lista: %s", (char *)newel->content);
	return (0);
}*/

/*Description: Allocates (with malloc(3)) and returns a new node.
The member variable ’content’ is initialized with
the value of the parameter ’content’. The variable
’next’ is initialized to NULL.
Return Value: The new node*/