#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

t_list	*swap(t_list *list);
void	push(t_list **list1, t_list **list2);
void	print_list(t_list *list_A, t_list *list_B);
t_list	*fill_list(t_list *list,char **element);

#endif