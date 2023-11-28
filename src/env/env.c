#include "env.h"

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
}