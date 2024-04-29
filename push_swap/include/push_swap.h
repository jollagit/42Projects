#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

t_list	*swap(t_list *list);
t_list	*rotate(t_list *list);
void	reverse_rotate(t_list **list);
void	push(t_list **list1, t_list **list2);
char	**check_parameter(int argc, char **argv);
t_list	*fill_list(t_list *list,char **element);
void	print_list(t_list *list_A, t_list *list_B);

#endif