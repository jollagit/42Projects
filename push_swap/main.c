/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:07:52 by gvigano           #+#    #+#             */
/*   Updated: 2024/05/10 15:43:36 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*list_a;
	t_list	*list_b;
	char	**str;

	str = NULL;
	if (argc < 2)
		return (0);
	str = check_parameter(argc, argv);
	if (!str)
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	list_a = NULL;
	list_b = NULL;
	list_a = fill_list(list_a, str);
	if (ft_lstsize(list_a) < 2)
	{
		free_all(&list_a, &list_b, &str);
		return (0);
	}
	list_a = push_swap(list_a, list_b);
	print_list(list_a, list_b);
	free_all(&list_a, &list_b, &str);
	return (0);
}
