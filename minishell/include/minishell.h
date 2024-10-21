/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:18:20 by gvigano           #+#    #+#             */
/*   Updated: 2024/10/21 16:00:33 by gvigano          ###   ########.fr       */
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

typedef struct s_token
{
	char			**value;
	struct s_token	*next;
} t_token;

typedef struct s_redir
{
	int				type;
	char			*name;
	struct s_redir	*next;
} t_redir;


#endif