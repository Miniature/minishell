/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:04:05 by wdavey            #+#    #+#             */
/*   Updated: 2023/11/28 16:25:03 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "command.h"
#include "libft.h"
#include "str.h"
#include "utils.h"

static char	*get_path_env(t_command cmd)
{
	char	**env;

	env = *cmd.envp;
	while (*env)
	{
		if (!ft_strncmp(*env, "PATH=", 5))
		{
			return (*env);
		}
		env++;
	}
	return (DEFAULT_PATH);
}

static char	*find_in_env(t_command cmd)
{
	char	*end;
	char	**path;
	size_t	iii;
	char	*check;

	end = ft_strjoin("/", cmd.argv[0]);
	path = ft_split(get_path_env(cmd) + 5, ':');
	iii = -1;
	while (path[++iii])
	{
		check = ft_strjoin(path[iii], end);
		if (!access(check, X_OK))
		{
			free(end);
			free_all(path);
			return (check);
		}
		free(check);
	}
	free(end);
	free_all(path);
	return (NULL);
}

char	*resolve_path(t_command cmd)
{
	char	*str;
	char	*cwd;

	if ('/' == cmd.argv[0][0])
		str = ft_strdup(cmd.argv[0]);
	else if (str_has_any_char(cmd.argv[0], '/'))
	{
		str = getcwd(NULL, -1);
		cwd = ft_strjoin(str, "/");
		free(str);
		str = ft_strjoin(cwd, cmd.argv[0]);
		free(cwd);
	}
	else
	{
		str = find_in_env(cmd);
	}
	if (!access(str, X_OK))
		return (str);
	free(str);
	return (NULL);
}
