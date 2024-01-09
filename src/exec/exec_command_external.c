/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command_external.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:41:36 by wdavey            #+#    #+#             */
/*   Updated: 2024/01/09 16:44:23 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "command.h"
#include "env.h"
#include "utils.h"

static void	exec_command_external_fork(char *cmd_path, t_command cmd)
{
	if (dup2(cmd.fd[FD_IN], STDIN_FILENO) == -1)
	{
		perror("minishell: exec");
	}
	else if (dup2(cmd.fd[FD_OUT], STDOUT_FILENO) == -1)
	{
		perror("minishell: exec");
	}
	else
	{
		execve(cmd_path, cmd.argv, *cmd.envp);
		perror("minishell: exec");
	}
	exit(1);
}

#define NOTFOUND_START "minishell: "
#define NOTFOUND_END ": command not found\n"

int	exec_command_external(t_command cmd)
{
	char	*cmd_path;
	pid_t	pid;

	ms_setenv(cmd.envp, ft_strjoin("_=", cmd.argv[0]));
	cmd_path = resolve_path(cmd);
	if (cmd_path == NULL || ft_strlen(cmd.argv[0]) == 0)
	{
		write(2, NOTFOUND_START, ft_strlen(NOTFOUND_START));
		write(2, cmd.argv[0], ft_strlen(cmd.argv[0]));
		write(2, NOTFOUND_END, ft_strlen(NOTFOUND_END));
		return (-1);
	}
	pid = fork();
	if (pid == -1)
		perror("minishell: exec");
	if (pid == 0)
	{
		exec_command_external_fork(cmd_path, cmd);
	}
	ms_setenv(cmd.envp, ft_strjoin("_=", array_last((void **)cmd.argv)));
	return (pid);
}
