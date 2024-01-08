/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_builtin_pwd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:44:28 by wdavey            #+#    #+#             */
/*   Updated: 2024/01/08 14:09:39 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "r_builtin.h"
#include "libft.h"

int	builtin_pwd(t_command cmd)
{
	char	*buf;

	(void)cmd;
	buf = getcwd(NULL, 0);
	if (buf != NULL)
	{
		write(cmd.fd[FD_OUT], buf, ft_strlen(buf));
		write(cmd.fd[FD_OUT], "\n", 1);
	}
	else
		perror("pwd");
	free(buf);
	return (0);
}
