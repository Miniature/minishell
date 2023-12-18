#include "r_builtin.h"
#include "libft.h"
#include <signal.h>
#include "r_signal.h"

void	ms_exit(t_command cmd)
{
	while (*(cmd.envp) != NULL)
	{
		free(*cmd.envp);
		cmd.envp++;
	}
	free(*cmd.envp);
}

int	builtin_exit(t_command cmd)
{
	(void)cmd;
	signal_handler(SIGQUIT);
	ms_exit(cmd);
}
