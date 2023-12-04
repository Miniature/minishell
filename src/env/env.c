/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:50:04 by wdavey            #+#    #+#             */
/*   Updated: 2023/12/04 19:33:51 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "utils.h"
#include "libft.h"
#include "str.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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

/* in "envp", set an associated environment variable to "value" if it exists,
or create a new environment variable at the end of "envp" by appending it to
the end of the array. */
void	ms_setenv(char ***envp, char *value)
{
	int		name_length;
	int		i;
	char	*equal;

	i = -1;
	equal = ft_strchr(value, '=');
	if (equal == NULL)
	{
		printf("Error: Invalid Environment Variable\n");
		return ;
	}
	name_length = equal - value;
	if (update_env(*envp, value, name_length) == 0)
	{
		*envp = array_append(envp, value);
	}
}

/* in "envp", find the environment variable called "name" and remove it, 
reallocating the memory accordingly to avoid memory leaks */
void	ms_unsetenv(char ***envp, char *name)
{
	int		i;
	int		name_length;
	char	**env;
	char	**new_env;

	name_length = ft_strlen(name);
	env = *envp;
	i = find_and_remove(env, name, name_length);
	new_env = realloc(env, i * sizeof(char *));
	if (new_env == NULL)
	{
		printf("Failed to reallocate memory ");
		printf("while unsetting environment variable.\n");
		return ;
	}
	*envp = new_env;
}

int	find_and_remove(char **env, char *name, int name_length)
{
	int	i;

	i = -1;
	while (env[++i] != NULL)
	{
		if (ft_strncmp(env[i], name, name_length) == 0
			&& env[i][name_length] == '=')
		{
			free(env[i]);
			while (env[i] != NULL)
			{
				env[i] = env[i + 1];
				i++;
			}
			break ;
		}
	}
	return (i);
}

bool	update_env(char **env, char *value, int name_length)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		if (0 == ft_strncmp(env[i], value, name_length + 1))
		{
			free(env[i]);
			env[i] = ft_strdup(value);
			return (1);
		}
	}
	return (0);
}
