/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command_builtin.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:49:36 by wdavey            #+#    #+#             */
/*   Updated: 2023/12/05 14:04:54 by wdavey           ###   ########.fr       */
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

	rval = f(cmd);
	pid = fork();
	if (pid == 0)
	{
		exit(rval);
	}
	return (pid);
}
