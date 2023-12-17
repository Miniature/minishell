/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:01:01 by wdavey            #+#    #+#             */
/*   Updated: 2023/12/18 07:35:18 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "libft.h"
#include "r_builtin.h"
#include "exec.h"
#include <unistd.h>

//last is NULL NULL
static const t_builtin	*get_builtins(void)
{
	return ((t_builtin []){
		(t_builtin){"echo", &builtin_echo},
		(t_builtin){"cd", &builtin_cd},
		(t_builtin){"pwd", &builtin_pwd},
		(t_builtin){"export", &builtin_export},
		(t_builtin){"unset", &builtin_unset},
		(t_builtin){"env", &builtin_env},
		(t_builtin){"exit", NULL},
		(t_builtin){NULL, NULL}
	});
}

int	exec_command(t_command cmd)
{
	size_t	iii;
	int		pid;

	iii = -1;
	while (get_builtins()[++iii].name != NULL)
	{
		if (ft_strncmp(cmd.argv[0], get_builtins()[iii].name, -1) == 0)
		{
			pid = exec_command_builtin(cmd, get_builtins()[iii].function);
			break ;
		}
	}
	if (get_builtins()[++iii].name == NULL)
		pid = exec_command_external(cmd);
	if (STDIN_FILENO != cmd.fd[FD_IN])
		close(cmd.fd[FD_IN]);
	if (STDOUT_FILENO != cmd.fd[FD_OUT])
		close(cmd.fd[FD_OUT]);
	return (pid);
}
