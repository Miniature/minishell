/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_builtin_export.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:00:57 by wdavey            #+#    #+#             */
/*   Updated: 2024/01/08 15:13:03 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r_builtin.h"
#include "env.h"
#include "libft.h"

int	builtin_export(t_command cmd)
{
	int	i;

	if (cmd.argv[1] == NULL)
	{
		i = 0;
		while ((*cmd.envp)[i])
		{
			ft_putendl_fd((*cmd.envp)[i], cmd.fd[FD_OUT]);
			i++;
		}
	}
	else
	{
		i = 1;
		while (cmd.argv[i])
		{
			ms_setenv(cmd.envp, ft_strdup(cmd.argv[i]));
			i++;
		}
	}
	return (0);
}
