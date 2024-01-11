/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_builtin_cd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:37:29 by wdavey            #+#    #+#             */
/*   Updated: 2024/01/11 14:31:37 by wdavey           ###   ########.fr       */
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
#define NOOLDPWD "minishell: cd: OLDPWD not set\n"

int	builtin_pwd(t_command cmd);

static char	*cd_dir(t_command cmd)
{
	char	*path;

	path = cmd.argv[1];
	if (path == NULL)
	{
		path = ms_getenv_value(cmd.envp, "HOME");
		if (path == NULL)
		{
			write(STDERR_FILENO, NOHOME, ft_strlen(NOHOME));
			return (NULL);
		}
	}
	else if (!ft_strncmp(path, "-", -1))
	{
		path = ms_getenv_value(cmd.envp, "OLDPWD");
		if (path == NULL)
		{
			write(STDERR_FILENO, NOOLDPWD, ft_strlen(NOOLDPWD));
			return (NULL);
		}
	}
	return (path);
}

static void	builtin_cd_error(char *path)
{
	char	*msg;

	msg = ft_strjoin("minishell: cd: ", path);
	perror(msg);
	free(msg);
}

int	builtin_cd(t_command cmd)
{
	char	*path;
	char	*oldpath;
	bool	print;

	path = cd_dir(cmd);
	if (path == NULL)
		return (1);
	print = cmd.argv[1] != NULL && !ft_strcmp(cmd.argv[1], "-");
	oldpath = getcwd(NULL, 0);
	if (chdir(path) != 0)
	{
		builtin_cd_error(path);
		free(oldpath);
		return (1);
	}
	if (print)
	{
		builtin_pwd(cmd);
	}
	ms_setenv(cmd.envp, ft_strjoin("OLDPWD=", oldpath));
	free(oldpath);
	return (0);
}
