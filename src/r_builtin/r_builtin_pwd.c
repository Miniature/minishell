#include <stdio.h>
#include "r_builtin.h"

void	builtin_pwd()
{
	char	buf[PATH_MAX];

	if (getcwd(buf, PATH_MAX) != NULL)
		printf("%s\n", buf);
	else
		perror("pwd");
}
