/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_builtin_echo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:42:27 by wdavey            #+#    #+#             */
/*   Updated: 2024/01/09 16:05:24 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "str.h"
#include "r_builtin.h"
#include "command.h"
#include "libft.h"

int	builtin_echo(t_command cmd)
{
	int		i;
	char	**args;
	bool	n;

	n = true;
	i = 1;
	if (!ft_strcmp(cmd.argv[1], "-n"))
	{
		n = false;
		i++;
	}
	args = cmd.argv;
	while (args[i])
	{
		write(cmd.fd[FD_OUT], args[i], ft_strlen(args[i]));
		if (args[i + 1] != NULL)
			write(cmd.fd[FD_OUT], " ", 1);
		i++;
	}
	if (n)
		write(cmd.fd[FD_OUT], "\n", 1);
	return (0);
}
