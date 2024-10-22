/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:22:26 by gvigano           #+#    #+#             */
/*   Updated: 2024/10/22 15:46:25 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	fill_list(t_token *data, t_redir *extrn)
{
	t_token	*new_element;
	t_redir	*new_redir;

	data->value = malloc(3 * sizeof(*data->value));
	data->value[0] = strdup("/usr/bin/cat");
	data->value[1] = strdup("-e");
	data->value[2] = NULL;
	extrn->type = '<';
	extrn->name = strdup("prova.txt");
	data->rd = extrn;
	
	new_element = malloc(sizeof(t_token));
	new_element->value = malloc(2 * sizeof(*new_element->value));
	new_element->value[0] = strdup("|");
	new_element->value[1] = NULL;
	data->next = new_element;
	data = data->next;

	new_element = malloc(sizeof(t_token));
	new_element->value = malloc (4 * sizeof(*new_element->value));
	new_element->value[0] = strdup("/usr/bin/grep");
	new_element->value[1] = strdup("-v");
	new_element->value[2] = strdup("aa");
	new_element->value[3] = NULL;
	new_element->rd = NULL;
	data->next = new_element;
	data = data->next;

	new_element = malloc(sizeof(t_token));
	new_element->value = malloc(2 * sizeof(*new_element->value));
	new_element->value[0] = strdup("|");
	new_element->value[1] = NULL;
	data->next = new_element;
	data = data->next;

	new_element = malloc(sizeof(t_token));
	new_element->value = malloc (3 * sizeof(*new_element->value));
	new_element->value[0] = strdup("/usr/bin/wc");
	new_element->value[1] = strdup("-l");
	new_element->value[2] = NULL;
	data->next = new_element;
	data = data->next;
	data->next = NULL;

	new_redir = malloc(sizeof(new_redir));
	new_redir->type = '>';
	new_redir->name = strdup("outfile.txt");
	data->rd = new_redir;
}

int	main(int argc, char *env[])
{
	t_token	*data;
	t_redir	*extrn;

	if (argc > 1)
		return (0);
	data = malloc(sizeof(t_token));
	extrn = malloc(sizeof(t_redir));
	fill_list(data, extrn);
	do_command(data, env);
	return (0);
}

// while (data != NULL)
// {
// 	i = 0;
// 	if (data->rd != NULL)
// 	{
// 		printf("%d ", data->rd->type);
// 		printf("%s", data->rd->name);
// 		write(1, " ", 1);
// 	}
// 	while (data->value != NULL && data->value[i] != NULL)
// 		printf(" %s ", data->value[i++]);
// 	write(1, " ", 1);
// 	data = data->next;
// }