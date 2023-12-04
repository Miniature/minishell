/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_builtin_echo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:42:27 by wdavey            #+#    #+#             */
/*   Updated: 2023/12/04 17:04:15 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "r_builtin.h"
#include "command.h"

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
	print_echo(cmd.argv, n);
	return (0);
}

void	print_echo(char **args, bool n)
{
	int	i;

	i = 1;
	while (args[i])
	{
		printf("%s", args[i]);
		if (args[i] != NULL)
			printf(" ");
		i++;
	}
	if (n == 0)
		printf("\n");
}
