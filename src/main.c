/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:10:56 by wdavey            #+#    #+#             */
/*   Updated: 2024/01/09 15:23:06 by wdavey           ###   ########.fr       */
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
#include "readline/readline.h"
#include "readline/history.h"

int	engine(char ***envp);

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
	char	*shlvl;
	char	**env;

	(void)argc;
	(void)argv;
	env = copy_envp(envp);
	shlvl = ms_getenv(&env, "SHLVL");
	if (NULL == shlvl)
		ms_setenv(&env, "SHLVL=1");
	else
	{
		shlvl = ft_itoa(ft_atoi(ft_strchr(shlvl, '=') + 1) + 1);
		ms_setenv(&env, string_addcstr(&(t_string){ft_strdup("SHLVL="), 7},
				shlvl)->cstr);
		free(shlvl);
	}
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	engine(&env);
	free_all(env);
	rl_clear_history();
	printf("exit\n");
	return (0);
}
