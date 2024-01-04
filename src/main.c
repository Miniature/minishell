/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:10:56 by wdavey            #+#    #+#             */
/*   Updated: 2024/01/01 11:02:25 by wdavey           ###   ########.fr       */
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

int	g_signal;

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

/*
void	main_debug(int argc, char **argv, char ***envp)
{

	(void)argc;
	(void)argv;
	printf("%s\n", ms_getenv(envp, "PATH"));
	ms_setenv(envp, ft_strdup("PATH=NONE"));
	printf("%s\n", ms_getenv(envp, "PATH"));
	printf("%s\n", ms_getenv(envp, "ASDASD"));
	ms_setenv(envp, ft_strdup("ASDASD=NONE"));
	printf("%s\n", ms_getenv(envp, "ASDASD"));
	exec_command((t_command){(char *[]){"unset", "ASDASD", NULL}, envp,
	{0, 1}});
	printf("%s\n", ms_getenv(envp, "ASDASD"));
	char	**tokens;
	size_t	iii;
	printf("tokenize\n");
	tokens = tokenize_input("arg0 $PATH $ASDASD \"arg2 arg2 arg2\" arg3>arg5.tmp",
			envp);
	iii = -1;
	while (NULL != tokens[++iii])
	{
		printf("%lu %s\n", iii, tokens[iii]);
	}
	printf("parse\n");
	t_list	*cmds = build_commands(tokens, envp);
	iii = -1;
	t_command	*cmd = (t_command*)cmds->content;
	while (NULL != ((t_command *)cmds->content)->argv[++iii])
	{
		char	*arg = cmd->argv[iii];
		(void)arg;
		printf("%lu %s\n", iii, ((t_command *)cmds->content)->argv[iii]);
		fflush(stdout);
	}
	ft_lstclear(&cmds, (void(*)(void *))&command_free);
	free_all(tokens);
	tokens = tokenize_input("echo \"test string->exec chain\"", envp);
	cmds = build_commands(tokens, envp);
	exec_command(*(t_command *)cmds->content);
	free_all(tokens);
	ft_lstclear(&cmds, (void(*)(void *))&command_free);
	exec_command((t_command)
	{
		(char *[]){
			"echo", "dshfjsd", "aaaaaa", NULL
		},
		envp,
		{0, 1}
	});
	exec_command((t_command)
	{
		(char *[]){
			"export", ft_strdup("TESTAHSJ=TEST"), NULL
		},
		envp,
		{0, 1}
	});
	exec_command((t_command)
	{
		(char *[]){
			"env", NULL
		},
		envp,
		{0, 1}
	});
}
*/

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
	ms_setenv(&env, "exit=0");
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	//main_debug(argc, argv, &env);
	engine(&env);
	free_all(env);
	rl_clear_history();
	printf("exit\n");
	return (0);
}
