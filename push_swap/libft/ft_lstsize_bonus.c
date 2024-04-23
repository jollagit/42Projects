/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:19:45 by gvigano           #+#    #+#             */
/*   Updated: 2023/11/01 16:24:28 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*element;

	i = 0;
	element = lst;
	while (element != NULL)
	{
		i++;
		element = element->next;
	}
	return (i);
}
/*int	main(int argc, char *argv[])
{
	t_list	*newel;
	t_list	*lista;
	
	if (argc != 3)
		return (0);
	lista = NULL;
	newel = ft_lstnew(argv[1]);
	ft_lstadd_back(&lista, newel);
	newel = ft_lstnew(argv[2]);
	ft_lstadd_back(&lista, newel);
	printf("la size della lista: %d \n", ft_lstsize(lista));
	return (0);
}*/

/*Description: Counts the number of nodes in a list.
Return Value: The length of the list*/