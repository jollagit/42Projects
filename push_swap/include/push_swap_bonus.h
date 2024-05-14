/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:27:45 by gvigano           #+#    #+#             */
/*   Updated: 2024/05/14 20:21:07 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

#include "libft.h"

int		check_error(char *str);
int		check_input(char **argv);
t_list	*push_swap(t_list *list_a);
t_list	*swap(t_list *list, char c);
int		check_list(t_list **list_a);
t_list	*rotate(t_list *list, char c);
char	**fill_mat(int argc, char **argv);
t_list	*reverse_rotate(t_list *list, char c);
char	**check_parameter(int argc, char **argv);
t_list	*fill_list(t_list *list, char **element);
void	push(t_list **list1, t_list **list2, char c);
void	free_all(t_list **list1, t_list **list2, char ***str);

#endif