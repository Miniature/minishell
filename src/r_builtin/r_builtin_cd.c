/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_builtin_cd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:37:29 by wdavey            #+#    #+#             */
/*   Updated: 2023/11/28 16:36:36 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include "env.h"
#include "r_builtin.h"
#include "libft.h"

int	builtin_cd(t_command cmd)
{
	char	*path;
	char	*oldpath;

	path = cmd.argv[1];
	oldpath = ms_getenv(cmd.envp, "PATH");
	if (path == NULL)
	{
		path = ms_getenv(cmd.envp, "HOME");
	}
	else if (!ft_strncmp(path, "-", -1))
	{
		path = ms_getenv(cmd.envp, "OLDPWD");
		printf("%s\n", path);
	}
	if (chdir(path) != 0)
	{
		perror("cd");
		return (1);
	}
	ms_setenv(cmd.envp, path);
	ms_setenv(cmd.envp, oldpath);
	return (0);
}
