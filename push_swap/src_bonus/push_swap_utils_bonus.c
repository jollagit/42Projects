/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:07:36 by gvigano           #+#    #+#             */
/*   Updated: 2024/05/14 23:08:55 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_list(t_list **list_a)
{
	t_list	*current;

	current = *list_a;
	while (current->next)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

void	free_all(t_list **list1, t_list **list2, char ***str)
{
	size_t	i;

	i = 0;
	if (list1 != NULL)
		ft_lstclear(list1);
	if (list2 != NULL)
		ft_lstclear(list2);
	while ((*str)[i])
		free((*str)[i++]);
	free((*str));
}

char	**fill_mat(int argc, char **argv)
{
	size_t	i;
	size_t	t;
	char	**mat;

	i = 1;
	t = 0;
	if (argc > 2)
	{
		if (check_input(argv) == 0)
			return (NULL);
		mat = ft_calloc(argc, sizeof(char *));
		if (!mat)
			return (NULL);
		while (argv[i])
			ft_strlcpy(&mat[t++], argv[i++]);
	}
	else
		mat = ft_split(argv[1], ' ');
	return (mat);
}

t_list	*fill_list(t_list *list, char **element)
{
	size_t	i;
	t_list	*new_element;

	if (!element)
		return (list);
	i = 0;
	while (element[i])
	{
		new_element = ft_lstnew(ft_atoi(element[i++]));
		ft_lstadd_back(&list, new_element);
	}
	return (list);
}
