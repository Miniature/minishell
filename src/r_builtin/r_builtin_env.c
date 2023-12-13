#include "r_builtin.h"
#include "libft.h"

int	builtin_env(t_command cmd)
{
	int	i;

	i = 0;
	while ((*cmd.envp[i])
	{
		ft_putendl_fd((*cmd.envp)[i], cmd.fd[FD_OUT]);
		i++;
	}
	return (0);
}
