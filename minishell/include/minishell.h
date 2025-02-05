/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliaviga <giuliaviga@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:43:03 by mchiaram          #+#    #+#             */
/*   Updated: 2025/02/04 16:49:09 by giuliaviga       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "struct.h"
# include "builtin.h"
# include "parse_utils.h"
# include <stdlib.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

int			init(t_parse *data, t_token *tok, char **envp);
void		check_pid(t_token *data, int pid);
void		handle_pipe(t_token *data, int fd[2]);
void		do_command(t_token *data);
void		handle_redir(t_token *data);
void		fill_t_token(t_parse *data, t_token *tok);
void		execute_builtin(t_token *data, char *builtin, int fd1);
void		free_parse(t_parse *data);
void		free_token(t_token *tok);
void		free_environment(t_environ *env);
char		*ft_getenv(char **env, char *val);
t_environ	*init_env(char **envp);

#endif