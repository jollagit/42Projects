/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:19:50 by mchiaram          #+#    #+#             */
/*   Updated: 2025/02/05 19:59:22 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "struct.h"

void	ft_exit(t_token *data);
void	ft_pwd(t_token *data, int fd);
void	ft_echo(t_token *data, int fd);
void	ft_env(t_token *data);
void	print_var_name_error(char *var_name);
void	print_export_env(char **env);
int		ft_export(t_token *data);
int		valid_var_name(char *var);
char	**ft_unset(char **env, char *remove);
int		ft_cd(t_token *data);

#endif