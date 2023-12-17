/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:21:34 by wdavey            #+#    #+#             */
/*   Updated: 2023/12/13 21:01:46 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include "command.h"
#include <stdio.h>

size_t	token_unexpected(char **args, t_command *command)
{
	(void)command;
	printf("minishell: syntax error near unexpected token: %s\n", *args);
	return (-1);
}

//heredoc
size_t	token_2lt(char **args, t_command *command)
{
	//todo
	(void)args;
	(void)command;
	return (0);
}

size_t	token_1lt(char **args, t_command *command)
{
	if (STDIN_FILENO != command->fd[FD_IN])
		close(command->fd[FD_IN]);
	command->fd[FD_IN] = open(args[1], O_RDONLY);
	if (0 > command->fd[FD_IN])
		return (-1);
	return (1);
}

size_t	token_2gt(char **args, t_command *command)
{
	if (STDOUT_FILENO != command->fd[FD_OUT])
		close(command->fd[FD_OUT]);
	command->fd[FD_OUT] = open(args[1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (0 > command->fd[FD_OUT])
		return (-1);
	return (1);
}

size_t	token_1gt(char **args, t_command *command)
{
	if (STDOUT_FILENO != command->fd[FD_OUT])
		close(command->fd[FD_OUT]);
	command->fd[FD_OUT] = open(args[1], O_WRONLY | O_CREAT, 0644);
	if (0 > command->fd[FD_OUT])
		return (-1);
	return (1);
}
