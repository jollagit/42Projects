/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:07:52 by gvigano           #+#    #+#             */
/*   Updated: 2024/05/14 23:16:32 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <time.h>

int	main(int argc, char *argv[])
{
	t_list	*list_a;
	t_list	*list_b;
	char	**str;

	str = NULL;
	if (argc < 2)
		return (1);
	str = check_parameter(argc, argv);
	if (!str)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	list_a = NULL;
	list_b = NULL;
	list_a = fill_list(list_a, str);
	if (ft_lstsize(list_a) < 2)
	{
		free_all(&list_a, &list_b, &str);
		return (1);
	}
	list_a = push_swap(list_a, list_b);
	free_all(&list_a, &list_b, &str);
	return (0);
}

// static void	print_list(t_list *list_A, t_list *list_B)
// {
// 	ft_printf("a)\tb)\n");
// 	while (list_A || list_B)
// 	{
// 		if (list_A)
// 		{
// 			ft_printf("%d\t", list_A->content);
// 			list_A = list_A->next;
// 		}
// 		else
// 			ft_printf("\t");
// 		if (list_B)
// 		{
// 			ft_printf("%d\n", list_B->content);
// 			list_B = list_B->next;
// 		}
// 		else
// 			printf("\n");
// 	}
// 	return ;
// }

// int	main(void)
// {
// 	t_list	*list_a;
// 	t_list	*list_b;
// 	char	**str;
// 	int		size;
// 	char	**str2;

// 	int int_min, int_max;
// 	size = 501;
// 	str2 = ft_calloc((size + 1), sizeof(char *));
// 	int_min = -1000000;
// 	int_max = 1000000;
//     srand(time(NULL));
//     for (int i = 0; i < size; i++) {
//         int num = int_min + rand() % (int_max - int_min + 1);
// 		str2[i] = ft_itoa(num);
// 		ft_printf("%s ", str2[i]);
//     }
// 	str = check_parameter(size, str2);
// 	if (!str)
// 	{
// 		ft_putendl_fd("Error", 2);
// 		return (0);
// 	}
// 	list_a = NULL;
// 	list_b = NULL;
// 	list_a = fill_list(list_a, str);
// 	if (ft_lstsize(list_a) < 2)
// 	{
// 		free_all(&list_a, &list_b, &str);
// 		return (0);
// 	}
// 	list_a = push_swap(list_a, list_b);
// 	//print_list(list_a, list_b);
// 	if (!check_list(&list_a))
// 		ft_putendl_fd("LIST NOT SORTED!", 2);
// 	free_all(&list_a, &list_b, &str);
// 	return (0);
// }
