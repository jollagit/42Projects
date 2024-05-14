/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:09:47 by gvigano           #+#    #+#             */
/*   Updated: 2024/05/13 21:28:36 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

t_list			*swap(t_list *list, char c);
t_list			*rotate(t_list *list, char c);
t_list			*push_swap(t_list *list1, t_list *list2);
t_list			*sort_three(t_list *list);
int				check_list(t_list **list_a);
void			get_size(t_list *la, t_list *lb, size_t *sa, size_t *sb);
t_list			*reverse_rotate(t_list *list, char c);
char			**fill_mat(int argc, char **argv);
int				check_input(char **argv);
size_t			find_index(t_list *list, int target);
t_list			*sort_list(t_list *list_a, t_list *list_b);
void			push(t_list **list1, t_list **list2, char c);
char			**check_parameter(int argc, char **argv);
t_list			*fill_list(t_list *list, char **element);
void			free_all(t_list **list1, t_list **list2, char ***str);
char			*search_max_min(int target, t_list *list_a);
t_list			*sort_list_back(t_list *list_b, t_list *list_a);
int				sort_back_simulator(t_list *list_a, t_list *list_b);

#endif