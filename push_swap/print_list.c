#include "push_swap.h"

void	print_list(t_list *list)
{
	t_list	*current;

	current = list;
	while (current != NULL)
	{
		ft_printf("%d\n", current->content);
		current = current->next;
	}
	return ;
}
