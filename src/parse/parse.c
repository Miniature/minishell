/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:09:47 by wdavey            #+#    #+#             */
/*   Updated: 2023/12/05 17:54:39 by wdavey           ###   ########.fr       */
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

static t_token_action	*token_actions(void)
{
	return ((t_token_action[]){
		{"<<", &token_2lt},
		{"<", &token_1lt},
		{">>", &token_2gt},
		{">", &token_1gt},
		{NULL, NULL}
	});
}

static t_token_action	find_action(char *token)
{
	size_t			iii;

	iii = -1;
	while (NULL != token_actions()[++iii].token)
	{
		if (0 == ft_strncmp(token, token_actions()[iii].token, -1))
			return (token_actions()[iii]);
	}
	return ((t_token_action){NULL, NULL});
}

static t_command	*generate_command(char ***envp)
{
	return (ft_memcpy(malloc(sizeof(t_command)),
			&((t_command)
				{
					ft_calloc(1, sizeof(char *)),
					envp,
					{STDIN_FILENO, STDOUT_FILENO}
				}),
			sizeof(t_command)));
}

t_list	*build_commands(char **tokens, char ***envp)
{
	t_list		*commands;
	size_t		iii;
	size_t		action_n;
	t_command	*current;
	int			link[2];

	commands = NULL;
	iii = -1;
	current = generate_command(envp);
	while (tokens[++iii])
	{
		if (0 == ft_strncmp(tokens[iii], "|", -1))
		{
			pipe(link);
			if (STDOUT_FILENO == current->fd[FD_OUT])
				current->fd[FD_OUT] = link[0];
			else
				close(link[0]);
			ft_lstadd_back(&commands, ft_lstnew(current));
			current = generate_command(envp);
		}
		else if (NULL != find_action(tokens[iii]).action)
		{
			action_n = find_action(tokens[iii]).action(tokens + iii, current);
			if (0 < action_n)
				iii += action_n;
			else
			{
				command_free(current);
				ft_lstclear(&commands, (void (*)(void *))(&command_free));
				return (NULL);
			}
		}
		else
		{
			array_append(&(current->argv), tokens[iii]);
		}
	}
	ft_lstadd_back(&commands, ft_lstnew(current));
	return (commands);
}
