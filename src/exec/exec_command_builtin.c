/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command_builtin.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:49:36 by wdavey            #+#    #+#             */
/*   Updated: 2023/12/04 19:05:35 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	exec_command_builtin(t_command cmd, int (*f)(t_command))
{
	int		rval;
	pid_t	pid;

	pid = fork();
	if (0 == pid)
	{
		rval = 1;
		if (-1 == dup2(cmd.fd[FD_IN], STDIN_FILENO))
		{
			perror("minishell: exec");
		}
		else if (-1 == dup2(cmd.fd[FD_OUT], STDOUT_FILENO))
		{
			perror("minishell: exec");
		}
		else
			rval = f(cmd);
		exit(rval);
	}
	return (pid);
}
