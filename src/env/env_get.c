/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:27:26 by wdavey            #+#    #+#             */
/*   Updated: 2024/01/08 14:29:17 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* in "envp", find and return a pointer to the environment
containing the input parameter "name". */
char	*ms_getenv(char ***envp, char *name)
{
	char	**env;
	int		i;
	int		size;

	i = 0;
	env = *envp;
	size = ft_strlen(name);
	while (env[i])
	{
		if (!ft_strncmp(env[i], name, size) && env[i][size] == '=')
			return (env[i]);
		i++;
	}
	return (NULL);
}

char	*ms_getenv_value(char ***envp, char *name)
{
	char	*value;

	value = ms_getenv(envp, name);
	if (value != NULL)
		return (value + ft_strlen(name) + 1);
	return (NULL);
}
