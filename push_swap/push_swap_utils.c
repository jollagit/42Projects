/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:07:36 by gvigano           #+#    #+#             */
/*   Updated: 2024/05/02 18:11:29 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*fill_list(t_list *list,char **element)
{
	t_list	*new_element;
	size_t	i;

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

void	print_list(t_list *list_A, t_list *list_B)
{
	ft_printf("a)\tb)\n");
	while (list_A || list_B)
	{
		if (list_A)
		{
			ft_printf("%d\t", list_A->content);
			list_A = list_A->next;
		}
		else 
			ft_printf("\t");
		if (list_B)
		{
			ft_printf("%d\n", list_B->content);
			list_B = list_B->next;
		}
		else
			printf("\n");
	}
	return ;
}

char	**check_parameter(int argc, char **argv)
{
	int		i;
	size_t	t;
	char	**str;

	if (!argv)
		return (NULL);//error
	t = 0;
	i = 1;
	if (argc > 2)
	{
		str = malloc((argc) * (sizeof(char *)));
		if (!str)
			return (NULL);
		while (i < argc)
			ft_strlcpy(&str[t++], argv[i++]);
	}
	else 
		str = ft_split(argv[1], ' ');
	return (str);
}
