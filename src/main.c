/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:10:56 by wdavey            #+#    #+#             */
/*   Updated: 2023/11/29 17:43:13 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "r_signal.h"
#include "env.h"
#include <stdlib.h>
#include "utils.h"

t_signal	g_signal;

char	**tokenize_input(char *str, char ***envp);

//envp gets edited, so it needs to not be in static memory
static char	**copy_envp(char **envp)
{
	char	**copy;
	size_t	size;

	size = 0;
	while (envp[size])
		size++;
	copy = malloc(sizeof(*copy) * (size + 1));
	while (size != -1UL)
	{
		copy[size] = NULL;
		if (envp[size])
			copy[size] = ft_strdup(envp[size]);
		size--;
	}
	return (copy);
}

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	(void)envp;
	envp = copy_envp(envp);
	printf("%s\n", ms_getenv(&envp, "PATH"));
	ms_setenv(&envp, "PATH=NONE");
	printf("%s\n", ms_getenv(&envp, "PATH"));
	ms_setenv(&envp, "ASDASD=NONE");
	printf("%s\n", ms_getenv(&envp, "ASDASD"));
	printf("tokenize\n");
	char **tokens = tokenize_input("arg0 arg1 \"arg2 arg2 arg2\" arg3>arg5", &envp);
	for(int iii = 0; tokens[iii]; iii++)
	{
		printf("%i %s\n", iii, tokens[iii]);
	}
	free_all(envp);
	return (0);
}
