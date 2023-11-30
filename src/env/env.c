#include "env.h"
#include "utils.h"
#include "libft.h"

char	*ms_getenv(char ***envp, char *name)
{
	char	**env;

	env = *envp;
	while (*env)
	{
		if (!ft_strncmp(*env, name, ft_strlen(name)))
		{
			return (*env);
		}
		env++;
	}
	return (DEFAULT_PATH);
}

void	ms_setenv(char ***envp, char *value)
{
	int		name_length;
	int		i;
	char	**env;
	char	*equal;
	
	env = *envp;
	i = -1;
	equal = ft_strchr(value, '=');
	if (equal == NULL)
	{
		printf("Error: Invalid Environment Variable\n");
		return ;
	}
	name_length = equal - value;
	if (update_env(env, value, name_length) == 0)
	{
		env = array_append(&env, value);
		free(*envp);
		*envp = env;
	}
}

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
	int i;

	i = -1;
	while (env[++i] != NULL)
	{
		if (ft_strncmp(env[i], char *value, int name_length) == 0
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
		if (ft_strncmp(env[i], value, name_length + 1))
		{
			if (ft_strnequ(env[i], value, ft_strlen(value)) == 0)
			{			
				free(env[i]);
				env[i] = ft_strdup(value);
			}
			return (1);
		}
	}
	return (0);
}
