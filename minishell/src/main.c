/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:22:26 by gvigano           #+#    #+#             */
/*   Updated: 2024/10/21 16:44:43 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	fill_list(t_token *data, t_redir *extrn)
{
	t_token	*head;
	t_token	*new_element;

	head = data;
	data->value = malloc(2 * sizeof(*data->value));
	data->value[0] = "cat";
	data->value[1] = NULL;

	extrn->type = (<);

	extrn->name = malloc(sizeof(extrn->name));
	extrn->name = "prova.txt";
	extrn->type = (file);
	
	data->value[3] = "-e";
	data->value[4] = NULL;
	new_element = malloc(sizeof(t_token));
	new_element->value = malloc(2 * sizeof(*new_element->value));
	new_element->value[0] = "|";
	new_element->value = NULL;
	data->next = new_element;
	data = data->next;
	new_element = malloc(sizeof(t_token));
	new_element->value = malloc (4 * sizeof(*new_element->value));
	new_element->value[0] = "grep";
	new_element->value[1] = "-v";
	new_element->value[2] = "aa";
	new_element->value[3] = NULL;
	data->next = new_element;
	data = data->next;
	new_element->value = malloc(2 * sizeof(*new_element->value));
	new_element->value[0] = "|";
	new_element->value = NULL;
	data->next = new_element;
	data = data->next;
	new_element = malloc (5 * sizeof(*new_element->value));
	new_element->value[0] = "wc";
}

// int	main(void)
// {
// 	t_token	*data;
// 	t_redir	*extrn;

// 	data = malloc(sizeof(t_token));
// 	extrn = malloc(sizeof(t_redir));
// 	fill_list(data, extrn);
// }

int	main(int argc, char *argv[], char *envp[])
{
	int		pid;
	int		fdin;
	int		fdout;
	int 	tmpin;
	int 	tmpout;
	t_token	list;

	tmpin = dup(0);
	tmpout = dup(1);

// implementare redirection prima di fare il fork per i processi -->

	if (infile)
		fdin = open(infile, O_RDONLY);
	else
		fdin = dup(tmpin);

//cicla per il num di comandi "semplici" -->

	dup2(fdin, 0); // dup2 ?
	close (fdin);
	if (next->type != pipe && next->type != flag)
	{
		if (outfile)
			fdout = open(outfile,   );
		else
			fdout = dup(tmpout);
	}
	else
	{
		int	fd[2];

		pipe(fd);
		fdout = fd[1];
		fdin = fd[0];
	}
	dup2(fdout, 1);
	close(fdout);
	pid = fork();
	if (pid == 0)
	{
		execvp(scmd[i].args[0], scmd[i].args); // execvp ?
		perror("error");
		exit(1);
	} // fine ciclo for

	dup2(tmpin, 0);
	dup2(tmpout, 1);
	close(tmpin);
	close(tmpout);

	if (!background)
		waitpid(pid, NULL);
}
