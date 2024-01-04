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
#include "env.h"
#include <signal.h>
#include "r_signal.h"

int	builtin_exit(t_command cmd)
{
	char	*string;

	string = malloc(6);
	string = "exit=";
	if (cmd.argv[1] == NULL)
	{
		ms_setenv(cmd.envp, ft_strjoin(string, "1"));
		write(cmd.fd[FD_OUT], "exit\n", 5);
	}
	else if (cmd.argv[3] == NULL)
	{
		ms_setenv(cmd.envp, ft_strjoin(string, cmd.argv[1]));
		write(cmd.fd[FD_OUT], cmd.argv[1], ft_strlen(cmd.argv[1]));
	}
	else
	{
		write(cmd.fd[FD_OUT], "exit: too many arguments\n", 25);
	}
	free(string);
	return (0);
}
