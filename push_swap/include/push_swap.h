/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:09:47 by gvigano           #+#    #+#             */
/*   Updated: 2024/05/06 16:59:03 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

t_list		*swap(t_list *list);
t_list		*rotate(t_list *list);
t_list		*push_swap(t_list *list);
void		reverse_rotate(t_list **list);
char		**fill_mat(int argc, char **argv);
int			check_input(char **argv);
void		push(t_list **list1, t_list **list2);
char		**check_parameter(int argc, char **argv);
t_list		*fill_list(t_list *list, char **element);
void		print_list(t_list *list_A, t_list *list_B);
void		free_all(t_list **list1, t_list **list2, char ***str);

#endif