/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:18:20 by gvigano           #+#    #+#             */
/*   Updated: 2024/10/22 15:34:51 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// # include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>

enum tokenValues
{
	T_GENERAL	= -1,
	T_WHITESPC	= ' ',
	T_TAB		= '\t',
	T_NEWLINE	= '\n',
	T_QUOTE		= '\'',
	T_DQUOTE	= '\"',
	T_RED_IN	= '<',
	T_RED_OUT	= '>',
	T_PIPE		= '|',
	T_VAR		= '$',
	T_EXIT_STAT	= 1024,
	T_DELIM,
	T_RED_APPEN,
	T_COMMAND,
	T_FLAG,
	T_FILE,
	T_BUILTIN
};

typedef struct s_redir
{
	int				type;
	char			*name;
	struct s_redir	*next;
} t_redir;

typedef struct s_token
{
	char			**value;
	struct s_redir	*rd;
	struct s_token	*next;
} t_token;

void	do_command(t_token *data, char *env[]);

#endif