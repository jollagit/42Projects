/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliaviga <giuliaviga@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:20:12 by mchiaram          #+#    #+#             */
/*   Updated: 2025/02/04 14:33:48 by giuliaviga       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_prompt(t_token *tok)
{
	char	*prompt;
	char	cwd[1024];
	char	*user;
	char	*path;
	size_t	i;

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd() error");
		return (NULL);
	}
	user = ft_getenv(tok->env->var, "USER");
	if (!user)
		return (NULL);
	path = ft_strnstr(cwd, user, ft_strlen(cwd));
	i = 1;
	while (i++ < ft_strlen(user))
		path++;
	path[0] = '~';
	prompt = ft_strjoin("\033[1;32m", user);
	prompt = ft_freejoin(prompt, "\033[0m:\033[1;34m");
	prompt = ft_freejoin(prompt, path);
	prompt = ft_freejoin(prompt, "\033[0m$ ");
	return (prompt);
}

t_token	*init_token (t_token *tok, t_environ *env)
{
	tok = malloc(sizeof(t_token));
	tok->value = NULL;
	tok->env = env;
	tok->exit_stat = 0;
	tok->type = 0;
	tok->rd = NULL;
	tok->next = NULL;
	return (tok);
}

t_parse	*init_data(t_parse *data)
{
	data = malloc(sizeof(t_parse));
	data->value = NULL;
	data->next = NULL;
	return (data);
}

static char	*prompt_init(t_token *tok)
{
	char	*prompt;
	char	*input;

	prompt = get_prompt(tok);
	if (!prompt)
		return (NULL);
	input = readline(prompt);
	free (prompt);
	prompt = NULL;
	input = ft_freetrim(&input, " \t\n");
	return (input);
}

int	init(t_parse *data, t_token *tok, char **envp)
{
	char		*input;
	t_environ	*env;

	env = init_env(envp);
	while (1)
	{
		tok = init_token(tok, env);
		input = prompt_init(tok);
		if (input && *input)
		{
			data = init_data(data);
			add_history(input);
			input_parse(input, data, tok);
			free_all(data, NULL, NULL, input);
			do_command(tok);
		}
		else if (!input)
		{
			rl_clear_history();
			free_all(NULL, NULL, env, input);
			return (1);
		}
		free_token(tok);
	}
	return (0);
}
