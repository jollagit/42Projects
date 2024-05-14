/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:23:46 by gvigano           #+#    #+#             */
/*   Updated: 2024/05/14 21:11:33 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	check_size_list(t_list **list_a, t_list **list_b, char ***str)
{
	if (ft_lstsize(*list_a) < 2)
	{
		free_all(list_a, list_b, str);
		return (1);
	}
	return (0);
}

static int do_swap_push(t_list **list_a, t_list **list_b, char *move)
{
	if (ft_strncmp(move, "pa\n", ft_strlen(move)) == 0)
		push(list_b, list_a, '0');
	else if (ft_strncmp(move, "pb\n", ft_strlen(move)) == 0)
		push (list_a, list_b, '0');
	else if (ft_strncmp(move, "sa\n", ft_strlen(move)) == 0)
		*list_a = swap((*list_a), '0');
	else if (ft_strncmp(move, "sb\n", ft_strlen(move)) == 0)
		*list_b = swap((*list_b), '0');
	else
		return (0);
	return (1);
}

static int	do_moves(t_list **list_a, t_list **list_b, char *move)
{
	if (do_swap_push(list_a, list_b, move))
		return (1);
	if (ft_strncmp(move, "ra\n", ft_strlen(move)) == 0)
		*list_a = rotate((*list_a), '0');
	else if (ft_strncmp(move, "rb\n", ft_strlen(move)) == 0)
		*list_b = rotate((*list_b), '0');
	else if (ft_strncmp(move, "rr\n", ft_strlen(move)) == 0)
	{
		*list_a = rotate((*list_a), '0');
		*list_b = rotate((*list_b), '0');
	}
	else if (ft_strncmp(move, "rra\n", ft_strlen(move)) == 0)
		*list_a = reverse_rotate((*list_a), '0');
	else if (ft_strncmp(move, "rrb\n", ft_strlen(move)) == 0)
		*list_b = reverse_rotate((*list_b), '0');
	else if (ft_strncmp(move, "rrr\n", ft_strlen(move)) == 0)
	{
		*list_a = reverse_rotate((*list_a), '0');
		*list_b = reverse_rotate((*list_b), '0');
	}
	else
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_list	*list_a;
	t_list	*list_b;
	char	**str;
	char	*move;

	if (argc < 2)
		return (1);
	str = NULL;
	str = check_parameter(argc, argv);
	check_error(*str);
	list_a = NULL;
	list_b = NULL;
	list_a = fill_list(list_a, str);
	list_a = push_swap(list_a);
	check_size_list(&list_a, &list_b, &str);
	move = get_next_line(0);
	while (move)
	{
		if (!do_moves(&list_a, &list_b, move))
			break ;
		free (move);
		move = get_next_line(0);
	}
	if (check_list(&list_a) && ft_lstsize(list_b) == 0)
		ft_putendl_fd("OK", 2);
	else
		ft_putendl_fd("KO", 2);
	free (move);
	move = get_next_line(-42);
	free_all(&list_a, &list_b, &str);
	return (0);
}
