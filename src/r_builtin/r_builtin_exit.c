/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_builtin_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:00:54 by wdavey            #+#    #+#             */
/*   Updated: 2024/01/09 15:41:18 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r_builtin.h"
#include "libft.h"
#include "env.h"
#include <signal.h>
#include "r_signal.h"

#define NONNUMERR_START "minishell: exit: "
#define NONNUMERR_END ": numeric argument required\n"

int	builtin_exit(t_command cmd)
{
	if (cmd.argv[1] == NULL)
	{
		return (0);
	}
	else if (cmd.argv[2] == NULL)
	{
		if (str_has_all(cmd.argv[1], (bool (*)(char))&ft_isalnum)
			&& !str_has_any(cmd.argv[1], (bool (*)(char))&ft_isalpha))
			return (ft_atoi(cmd.argv[1]));
		write(cmd.fd[FD_OUT], NONNUMERR_START, ft_strlen(NONNUMERR_START));
		write(cmd.fd[FD_OUT], cmd.argv[1], ft_strlen(cmd.argv[1]));
		write(cmd.fd[FD_OUT], NONNUMERR_END, ft_strlen(NONNUMERR_END));
		return (255);
	}
	else
	{
		write(cmd.fd[FD_OUT], "exit: too many arguments\n", 25);
		return (1);
	}
}
