/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:46:36 by gvigano           #+#    #+#             */
/*   Updated: 2023/11/01 17:01:49 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printlist(t_list *list)
{
	t_list	*current = list;
	while(current != NULL)
	{
		printf("%p ", current->content);
		current = current->next;
	}
}
void	ft_delete(void *element)
{
	if (element != NULL)
		free(element);
}
int	main(int argc, char *argv[])
{
	t_list	*newel;
	t_list	*lista;
	
	if (argc != 3)
		return (0);
	lista = (t_list *)malloc(sizeof(t_list));
	lista = NULL;
	newel = ft_lstnew(argv[1]);
	ft_lstadd_front(&lista, newel);
	printf("lista:");
	ft_printlist(lista);
	ft_lstdelone(newel, ft_delete);
	printf("\n adesso la lista e':");
	ft_printlist(lista);
	return (0);
}
