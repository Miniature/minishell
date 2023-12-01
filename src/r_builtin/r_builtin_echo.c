#include <stdio.h>
#include "r_builtin.h"

int	builtin_echo(char **args)
{
	int		i;
	bool	n;

	n = 0;
	size = 0;
	i = 1;
	while (args[i] && n == 0)
	{
		if (ft_strcmp(args[i], "-n"))
			n = 1;
		i++;
	}
	print_echo(args, n);
}

void	print_echo(char **args, bool n)
{
	int	i;

	i = 1;
	while (args[i])
	{
		printf("%s", args[i]);
		if (args[i] != NULL)
			printf(" ");
		i++;
	}
	
	if (n == 0)
		printf("\n");
}