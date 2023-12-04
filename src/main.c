/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:10:56 by wdavey            #+#    #+#             */
/*   Updated: 2023/12/04 18:23:03 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "r_signal.h"
#include "env.h"
#include <stdlib.h>
#include "utils.h"
#include "command.h"
#include "libft.h"
#include "str.h"
#include "parse.h"

t_signal	g_signal;

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

void	main_debug(int argc, char **argv, char ***envp)
{
	char	**tokens;
	size_t	iii;

	(void)argc;
	(void)argv;
	printf("%s\n", ms_getenv(envp, "PATH"));
	ms_setenv(envp, "PATH=NONE");
	printf("%s\n", ms_getenv(envp, "PATH"));
	ms_setenv(envp, "ASDASD=NONE");
	printf("%s\n", ms_getenv(envp, "ASDASD"));
	printf("tokenize\n");
	tokens = tokenize_input("arg0 $PATH \"arg2 arg2 arg2\" arg3>arg5",
			envp);
	iii = -1;
	while (NULL != tokens[++iii])
	{
		printf("%lu %s\n", iii, tokens[iii]);
	}
	exec_command((t_command)
	{
		(char *[]){
		"echo", "dshfjsd", "aaaaaa", NULL
	},
		envp,
	{0, 1}
	});
}

int	main(int argc, char **argv, char **envp)
{
	char	*shlvl;

	envp = copy_envp(envp);
	shlvl = ms_getenv(&envp, "SHLVL");
	if (NULL == shlvl)
		ms_setenv(&envp, "SHLVL=1");
	else
	{
		shlvl = ft_itoa(ft_atoi(ft_strchr(shlvl, '=') + 1) + 1);
		ms_setenv(&envp, string_addcstr(&(t_string){ft_strdup("SHLVL="), 7},
				shlvl)->cstr);
		free(shlvl);
	}
	main_debug(argc, argv, &envp);
	free_all(envp);
	return (0);
}
