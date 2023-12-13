/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_builtin_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:00:40 by wdavey            #+#    #+#             */
/*   Updated: 2023/12/13 19:03:02 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r_builtin.h"
#include "libft.h"
#include <stdio.h>

int	builtin_env(t_command cmd)
{
	int	i;

	i = 0;
	while ((*cmd.envp)[i])
	{
		ft_putendl_fd((*cmd.envp)[i], cmd.fd[FD_OUT]);
		i++;
	}
	return (0);
}
