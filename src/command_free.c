/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:43:40 by wdavey            #+#    #+#             */
/*   Updated: 2023/12/13 20:12:51 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include <unistd.h>
#include <stdlib.h>

void	command_free(t_command *cmd)
{
	if (STDIN_FILENO != cmd->fd[FD_IN])
		close(cmd->fd[FD_IN]);
	if (STDOUT_FILENO != cmd->fd[FD_OUT])
		close(cmd->fd[FD_OUT]);
	free(cmd->argv);
	free(cmd);
}
