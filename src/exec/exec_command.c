/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:01:01 by wdavey            #+#    #+#             */
/*   Updated: 2023/11/28 16:30:19 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "libft.h"
#include "r_builtin.h"

typedef struct s_builtin
{
	char	*name;
	int		(*function)(t_command);
}	t_builtin;

//last is NULL NULL
static const t_builtin	*get_builtins(void)
{
	return ((t_builtin []){
		(t_builtin){"echo", NULL},
		(t_builtin){"cd", &builtin_cd},
		(t_builtin){"pwd", NULL},
		(t_builtin){"export", NULL},
		(t_builtin){"unset", NULL},
		(t_builtin){"env", NULL},
		(t_builtin){"exit", NULL},
		(t_builtin){NULL, NULL}
	});
}

int	exec_command(t_command cmd)
{
	size_t	iii;

	iii = -1;
	while (NULL != get_builtins()[++iii].name)
	{
		if (0 == ft_strncmp(cmd.argv[0], get_builtins()[iii].name, -1))
		{
			return (exec_command_builtin(cmd, get_builtins()[iii].function));
		}
	}
	return (exec_command_external(cmd));
}