#include "push_swap.h"

t_list	*fill_list(t_list *list,char **element)
{
	t_list	*new_element;
	size_t	i;

	if (!element)
		return (list);
	i = 1;
	while (element[i])
	{
		new_element = ft_lstnew(ft_atoi(element[i++]));
		ft_lstadd_back(&list, new_element);
	}
	return (list);
}





