/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:01:01 by wdavey            #+#    #+#             */
/*   Updated: 2023/12/04 19:35:07 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "libft.h"
#include "r_builtin.h"
#include "exec.h"

//last is NULL NULL
static const t_builtin	*get_builtins(void)
{
	return ((t_builtin []){
		(t_builtin){"echo", &builtin_echo},
		(t_builtin){"cd", &builtin_cd},
		(t_builtin){"pwd", &builtin_pwd},
		(t_builtin){"export", NULL},
		(t_builtin){"unset", &builtin_unset},
		(t_builtin){"env", NULL},
		(t_builtin){"exit", NULL},
		(t_builtin){NULL, NULL}
	});
}

int	exec_command(t_command cmd)
{
	size_t	iii;

	iii = -1;
	while (get_builtins()[++iii].name != NULL)
	{
		if (ft_strncmp(cmd.argv[0], get_builtins()[iii].name, -1) == 0)
		{
			return (exec_command_builtin(cmd, get_builtins()[iii].function));
		}
	}
	return (exec_command_external(cmd));
}
