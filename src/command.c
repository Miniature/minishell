/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:43:40 by wdavey            #+#    #+#             */
/*   Updated: 2023/12/13 21:01:59 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

t_command	*command_new(char ***envp)
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

void	command_free(t_command *cmd)
{
	if (STDIN_FILENO != cmd->fd[FD_IN])
		close(cmd->fd[FD_IN]);
	if (STDOUT_FILENO != cmd->fd[FD_OUT])
		close(cmd->fd[FD_OUT]);
	free(cmd->argv);
	free(cmd);
}
