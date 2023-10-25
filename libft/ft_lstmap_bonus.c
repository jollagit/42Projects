/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliaviga <giuliaviga@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:21:28 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/24 19:18:19 by giuliaviga       ###   ########.fr       */
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
