/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:40:43 by mchiaram          #+#    #+#             */
/*   Updated: 2025/02/04 11:59:32 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	sigquit_handler(int sig)
{
	(void)sig;
}

static void	sigint_handler(int sig)
{
	(void)sig;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

int	main(int ac, char **av, char **envp)
{
	t_parse	*data;
	t_token	*tok;

	(void)ac;
	(void)av;
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
	data = NULL;
	tok = NULL;
	if (!init(data, tok, envp))
		return (1);
	return (0);
}
