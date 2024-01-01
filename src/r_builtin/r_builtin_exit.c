/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_builtin_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:00:54 by wdavey            #+#    #+#             */
/*   Updated: 2023/12/13 19:00:54 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r_builtin.h"
#include "libft.h"
#include <signal.h>
#include "r_signal.h"

void	ms_exit(t_command cmd)
{
	while (*(cmd.envp) != NULL)
	{
		free(*cmd.envp);
		cmd.envp++;
	}
	free(*cmd.envp);
}

int	builtin_exit(t_command cmd)
{
	(void)cmd;
	signal_handler(SIGQUIT);
	ms_exit(cmd);
}
