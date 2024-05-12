#include "push_swap.h"

static void	do_r(t_list **list_b, t_list **list_a, char *maxmin, int target, size_t size_b)
{
	size_t	index_a;
	size_t	index_b;
	size_t	size_a;

	size_a = ft_lstsize((*list_a));
	index_b = find_index((*list_b), target);
	index_a = 0;
	if (maxmin)
		index_a = find_index((*list_a), ft_atoi(maxmin));
	while ((*list_b)->content != target || (maxmin && (*list_a)->content != ft_atoi(maxmin)))
	{
		if ((*list_b)->content != target && index_b <= (size_b / 2)
			&&index_b !=  0)
			(*list_b) = rotate((*list_b), 'b');
		else if ((*list_b)->content != target && index_b > (size_b / 2)
			&& index_b != size_b)
			(*list_b) = reverse_rotate((*list_b), 'b');
		else if (maxmin && ((*list_a)->content != ft_atoi(maxmin)
			&& index_a <= (size_a / 2)))
			(*list_a) = rotate((*list_a), 'a');
		else if (maxmin && ((*list_a)->content != ft_atoi(maxmin)
			&& index_a > (size_a / 2)))
			(*list_a) = reverse_rotate((*list_a), 'a');
	}
}

static void	do_rr(t_list **list_b, t_list **list_a, char *maxmin, int target, size_t size_b)
{
	size_t	index_a;
	size_t	index_b;
	size_t	size_a;

	size_a = ft_lstsize((*list_a));
	index_b = find_index((*list_b), target);
	index_a = find_index((*list_a), ft_atoi(maxmin));
	while ((*list_b)->content != target && (*list_a)->content != ft_atoi(maxmin))
	{
		if ((index_b > (size_b / 2) && index_a > (size_a / 2))
			|| (index_b > (size_b / 2) && (index_a + 1) == size_a))
		{
			(*list_a) = reverse_rotate((*list_a), '0');
			(*list_b) = reverse_rotate((*list_b), 'r');
		}
		else if (index_b <= (size_b / 2) && index_a <= (size_a / 2))
		{
			(*list_a) = rotate((*list_a), '0');
			(*list_b) = rotate((*list_b), 'r');
		}
		else
			break ;
	}
}

static t_list	*sort_list_a(t_list *list_a, size_t size)
{
	t_list	*current;
	int		min;
	size_t	index;

	min = INT_MAX;
	current = list_a;
	while (current)
	{
		if (current->content < min)
			min = current->content;
		current = current->next;
	}
	index = find_index(list_a, min);
	while (list_a->content != min)
	{
		if (index > (size / 2) || index == (size - 1))
			list_a = reverse_rotate(list_a, 'a');
		else
			list_a = rotate(list_a, 'a');
	}
	return (list_a);
}

t_list	*sort_list_back(t_list *list_b, t_list *list_a)
{
	int		bestnum;
	char	*maxmin;
	size_t	size_b;

	maxmin = NULL;
	while (ft_lstsize(list_b) > 0)
	{
		size_b = ft_lstsize(list_b);
		bestnum = sort_back_simulator(list_b, list_a);
		maxmin = search_max_min(bestnum, list_a);
		if (maxmin)
			do_rr(&list_b, &list_a, maxmin, bestnum, size_b);
		else
			list_a = sort_list_a(list_a, ft_lstsize(list_a));
		do_r(&list_b, &list_a, maxmin, bestnum, size_b);
		push(&list_b, &list_a, 'a');
		free (maxmin);
	}
	return (list_a);
}