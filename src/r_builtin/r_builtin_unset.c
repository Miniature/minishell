#include "r_builtin.h"
#include "libft.h"
#include "str.h"

int	builtin_unset(t_command cmd)
{
	int		i;
	int		name_length;
	char	*name;
	char	**env;

	env = *(cmd.envp);
	name = cmd.argv[1];
	name_length = ft_strlen(name);
	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], name, name_length) == 0
			&& env[i][name_length] == '=')
		{
			ms_unsetenv(env, name);
			break ;
		}
		i++;
	}
	return (0);
}
