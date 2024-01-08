/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_builtin_cd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:37:29 by wdavey            #+#    #+#             */
/*   Updated: 2024/01/08 14:49:34 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include "env.h"
#include "r_builtin.h"
#include "libft.h"
#include <stdlib.h>

#define NOHOME "minishell: HOME is not set\n"

int	builtin_cd(t_command cmd)
{
	char	*path;
	char	*oldpath;

	path = cmd.argv[1];
	oldpath = getcwd(NULL, 0);
	if (path == NULL)
	{
		path = ms_getenv_value(cmd.envp, "HOME");
		if (path == NULL)
		{
			free(oldpath);
			write(STDERR_FILENO, NOHOME, ft_strlen(NOHOME));
		}
	}
	else if (!ft_strncmp(path, "-", -1))
		path = ms_getenv_value(cmd.envp, "OLDPWD");
	if (chdir(path) != 0)
	{
		perror("cd");
		return (1);
	}
	ms_setenv(cmd.envp, ft_strjoin("OLDPWD=", oldpath));
	free(oldpath);
	return (0);
}

//		printf("%s\n", path); << Add to line 34 if needed there >>
