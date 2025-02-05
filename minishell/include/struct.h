/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliaviga <giuliaviga@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:43:01 by mchiaram          #+#    #+#             */
/*   Updated: 2025/02/04 14:33:28 by giuliaviga       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <linux/limits.h>

enum e_tokenValues
{
	T_GENERAL	= 1024,
	T_QUOTE,
	T_DQUOTE,
	T_EXIT_STAT,
	T_VAR,
	T_BUILTIN,
	T_COMMAND,
	T_PIPE,
	T_LIM,
	/* delimiters */
	T_RED_IN,
	T_RED_OUT,
	T_RED_APPEN,
	T_DELIM,
	/*ignore chars*/
	T_WHITESPC,
	T_TAB,
	T_NEWLINE
};

typedef struct s_environ
{
	char	**var;
}	t_environ;

typedef struct s_redir
{
	int				type;
	char			*name;
	struct s_redir	*next;
}	t_redir;

typedef struct s_token
{
	char			**value;
	t_environ		*env;
	int				exit_stat;
	int				type;
	t_redir			*rd;
	struct s_token	*next;
}	t_token;

typedef struct s_parse
{
	char			*value;
	int				type;
	struct s_parse	*next;
}	t_parse;

#endif