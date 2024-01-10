/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:10:56 by wdavey            #+#    #+#             */
/*   Updated: 2024/01/09 15:31:15 by wdavey           ###   ########.fr       */
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

void	default_envp(char ***envp)
{
	char	*shlvl;

	if (ms_getenv(envp, "PATH") == NULL)
		ms_setenv(envp, ft_strdup(DEFAULT_PATH));
	shlvl = ms_getenv(envp, "SHLVL");
	if (shlvl == NULL)
		ms_setenv(envp, ft_strdup("SHLVL=1"));
	else
	{
		shlvl = ft_itoa(ft_atoi(ft_strchr(shlvl, '=') + 1) + 1);
		ms_setenv(envp, string_addcstr(&(t_string){ft_strdup("SHLVL="), 7},
				shlvl)->cstr);
		free(shlvl);
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	**env;
	int		rval;

	(void)argc;
	(void)argv;
	env = copy_envp(envp);
	default_envp(&env);
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	rval = engine(&env);
	free_all(env);
	rl_clear_history();
	printf("exit\n");
	return (rval);
}
