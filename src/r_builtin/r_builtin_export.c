#include "r_builtin.h"
#include "env.h"
#include "libft.h"

int	builtin_export(t_command cmd)
{
	int	i;

	if (cmd.argv[1] == NULL)
	{
		i = 0;
		while ((*cm.envp)[i])
		{
			ft_putendl_fd((*cmd.envp)[i], cmd.fd[FD_OUT);
			i++;
		}
	}
	else
	{
		i = 1;
		while (cmd.argv[i])
		{
			ms_setenv(cmd.envp, cmd.argv[i]);
			i++;
		}
	}
	return (0);
}