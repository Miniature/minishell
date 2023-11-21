/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_external_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:41:36 by wdavey            #+#    #+#             */
/*   Updated: 2023/11/21 17:04:02 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "command.h"

static void	exec_command_forked(char *cmd_path, t_command cmd)
{
	if (-1 == dup2(cmd.fd[IN], STDIN_FILENO))
	{
		perror("minishell: exec");
		close(cmd.fd[IN]);
	}
	else if (-1 == dup2(cmd.fd[OUT], STDOUT_FILENO))
	{
		perror("minishell: exec");
		close(cmd.fd[OUT]);
	}
	else
	{
		execve(cmd_path, cmd.argv, cmd.envp);
		perror("minishell: exec");
	}
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	exit(1);
}

int	exec_external_command(t_command cmd)
{
	char	*cmd_path;
	pid_t	pid;

	cmd_path = resolve_path(cmd);
	if (NULL == cmd_path)
	{
		write(2, "minishell: command not found: ", 31);
		write(2, cmd.argv[0], ft_strlen(cmd.argv[0]));
		write(2, "\n", 1);
		return (-1);
	}
	pid = fork();
	if (-1 == pid)
		perror("minishell: exec");
	if (0 == pid)
	{
		exec_command_forked(cmd_path, cmd);
	}
	return (pid);
}
