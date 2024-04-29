/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:07:52 by gvigano           #+#    #+#             */
/*   Updated: 2024/04/29 19:06:49 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*static void	ft_free_str(char **str)
{
	if (str)
	{
		while (*str)
			free(*str++);
	}
}*/

int main (int argc, char *argv[])
{
	t_list	*listA;
	t_list	*listB;
	char	**str;
	int		i;

	str = NULL;
	if (argc > 1)
		str = check_parameter(argc, argv);
	listA = NULL;
	listB = NULL;
	i = 0;
	if (str)
	{
		listA = fill_list(listA, str);
		print_list(listA, listB);
		while (str[i])
			free(str[i++]);
		free(str);
	}
	ft_lstclear(&listA);
	ft_lstclear(&listB);
	return (0);
}

