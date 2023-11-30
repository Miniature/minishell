#include <stdio.h>
#include "r_builtin.h"

int	builtin_echo(char **args)
{
	int		i;
	int		size;
	bool	n;

	n = 0;
	size = 0;
	i = 1;
	while (args[size])
		size++;
	if (size > 1)
	{
		while (args[i] && !ft_strcmp(args[i], "-n"))

	}
}