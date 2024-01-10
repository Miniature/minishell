/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:09:47 by wdavey            #+#    #+#             */
/*   Updated: 2024/01/10 22:16:48 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>
#include "command.h"
#include "parse.h"
#include "utils.h"
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

//norminette can get fucked
static t_token_action	get_action(char *token)
{
	size_t			iii;
	t_token_action	*actions;

	actions = ((t_token_action[]){
		{"<<", &token_2lt},
		{"<", &token_1lt},
		{">>", &token_2gt},
		{">", &token_1gt},
		{NULL, NULL}
		});
	iii = -1;
	while (NULL != actions[++iii].token)
	{
		if (0 == ft_strncmp(token, actions[iii].token, -1))
			return (actions[iii]);
	}
	return ((t_token_action){NULL, NULL});
}

static t_command	*build_pipe(char ***envp, t_command *current,
	t_list **commands)
{
	int			link[2];

	pipe(link);
	if (STDOUT_FILENO == current->fd[FD_OUT])
		current->fd[FD_OUT] = link[1];
	else
		close(link[1]);
	ft_lstadd_back(commands, ft_lstnew(current));
	current = command_new(envp);
	current->fd[FD_IN] = link[0];
	return (current);
}

static void	clean(t_list *commands, t_command *current)
{
	ft_lstclear(&commands, (void (*)(void *))(&command_free));
	command_free(current);
}

static size_t	handle_action(char **tokens, t_command *current)
{
	if (NULL != get_action(tokens[1]).action)
	{
		printf("minishell: syntax error near unexpected token `%s'\n",
			tokens[1]);
		return (-1);
	}
	return (get_action(tokens[0]).action(tokens, current));
}

t_list	*build_commands(char **tokens, char ***envp)
{
	t_list		*commands;
	size_t		iii;
	size_t		action_n;
	t_command	*current;

	commands = NULL;
	iii = -1;
	current = command_new(envp);
	if (tokens[0] == NULL)
		array_append(&(current->argv), "");
	while (tokens[++iii])
	{
		if (0 == ft_strncmp(tokens[iii], "|", -1))
			current = build_pipe(envp, current, &commands);
		else if (NULL != get_action(tokens[iii]).action)
		{
			action_n = handle_action(tokens + iii, current);
			if (0 > action_n)
				return (clean(commands, current), NULL);
			iii += action_n;
		}
		else
			array_append(&(current->argv), tokens[iii]);
	}
	return (ft_lstadd_back(&commands, ft_lstnew(current)), commands);
}
