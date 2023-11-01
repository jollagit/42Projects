/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:58:58 by gvigano           #+#    #+#             */
/*   Updated: 2023/11/01 15:12:49 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}
/*int	main(int argc, char *argv[])
{
	t_list	*newel;
	t_list	*lista;
	
	if (argc != 2)
		return (0);
	lista = NULL;
	newel = ft_lstnew(argv[1]);
	ft_lstadd_front(&lista, newel);
	printf("il nuovo elemento della lista: %s", (char *)newel->content);
	return (0);
}*/

/*Description: Adds the node ’new’
at the beginning of the list.
Return Value: None*/