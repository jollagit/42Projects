/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliaviga <giuliaviga@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:19:50 by mchiaram          #+#    #+#             */
/*   Updated: 2025/02/05 10:32:23 by giuliaviga       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "minishell.h"

void	ft_env(t_token *data);
void	ft_exit(t_token *data);
void	ft_pwd(t_token *data, int fd);
void	ft_echo(t_token *data, int fd);

#endif