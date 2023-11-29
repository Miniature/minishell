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
