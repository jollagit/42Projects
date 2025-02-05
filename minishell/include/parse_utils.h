/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:17:58 by mchiaram          #+#    #+#             */
/*   Updated: 2025/02/04 13:29:35 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_UTILS_H
# define PARSE_UTILS_H

# include "struct.h"

void	free_all(t_parse *data, t_token *tok, t_environ *env, char *input);
int		input_parse(char *input, t_parse *data, t_token *tok);
int		fill_t_parse_values(char *input, t_parse *data);
int		fill_t_parse_types(t_parse *data, t_token *tok);
int		check_path_access(char *dir, char *value);
size_t	first_tok_copy(t_parse *data, t_token *tok, t_redir *rd, size_t i);
size_t	get_tok(t_parse *data, t_token *new_tok, t_redir *new_rd, size_t i);
int		check_if_builtin(char *value);
char	*expand_var(t_token *tok, char *var);
void	remove_quotes(t_parse *data);

#endif