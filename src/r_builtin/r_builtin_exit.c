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

int	builtin_exit(t_command cmd)
{
	int	status;

	if (cmd.args[1] == NULL)
	{
		exit(0);
	}
	else
	{
		status = atoi(args[1]);
		exit(cmd.exit_code);
	}
	return (0);
}
