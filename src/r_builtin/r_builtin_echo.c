/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_builtin_echo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:42:27 by wdavey            #+#    #+#             */
/*   Updated: 2023/12/13 19:22:48 by wdavey           ###   ########.fr       */
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
	bool	n;

	n = 0;
	i = 1;
	while (cmd.argv[i] && n == 0)
	{
		if (ft_strcmp(cmd.argv[i], "-n"))
			n = 1;
		i++;
	}
	print_echo(cmd, n);
	return (0);
}

void	print_echo(t_command cmd, bool n)
{
	int		i;
	char	**args;

	args = cmd.argv;
	i = 1;
	while (args[i])
	{
		write(cmd.fd[FD_OUT], args[i], ft_strlen(args[i]));
		if (args[i + 1] != NULL)
			write(cmd.fd[FD_OUT], " ", 1);
		i++;
	}
	if (n)
		write(cmd.fd[FD_OUT], "\n", 1);
}
