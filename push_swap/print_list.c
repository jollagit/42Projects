#include "push_swap.h"

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
