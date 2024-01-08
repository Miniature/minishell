/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:33:09 by wdavey            #+#    #+#             */
/*   Updated: 2024/01/08 15:43:22 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#include "parse.h"
#include "command.h"
#include "libft.h"
#include "env.h"
#include "str.h"
#include "readline/readline.h"
#include "readline/history.h"
#include "r_signal.h"

static char	*get_input(void)
{
	char	*input;

	input = readline("minishell> ");
	add_history(input);
	return (input);
}

static void	engine_run(t_list *cmds, char ***envp)
{
	t_list	*current;
	pid_t	last;
	int		stat_loc;
	char	*rvalstr;

	current = cmds;
	while (current)
	{
		last = exec_command(*(t_command *)current->content);
		current = current->next;
	}
	stat_loc = 0;
	if (0 < last)
	{
		waitpid(last, &stat_loc, 0);
	}
	else
		stat_loc = 127 << 8;
	while (-1 != wait(NULL))
		;
	rvalstr = ft_itoa(WEXITSTATUS(stat_loc));
	ms_setenv(envp, ft_strjoin("?=", rvalstr));
	free(rvalstr);
}

static void	engine_cleanup(char *input, char **tokens, t_list *cmds)
{
	free(input);
	free_all(tokens);
	ft_lstclear(&cmds, (void (*)(void *)) & command_free);
}

static void	engine_signals(char ***envp)
{
	if (g_signal == _SIGEXIT)
	{
		printf("Quit: %s\n", ms_getenv_value(envp, "?"));
	}
	g_signal = _SIGOKAY;
}

void	engine(char ***envp)
{
	char			*input;
	char			**tokens;
	t_list			*cmds;

	while (true)
	{
		input = NULL;
		while (!input || !ft_strlen(input))
			input = get_input();
		tokens = tokenize_input(input, envp);
		cmds = build_commands(tokens, envp);
		if (cmds && !cmds->next
			&& !ft_strncmp(((t_command *)cmds->content)->argv[0], "exit", -1))
			break ;
		engine_run(cmds, envp);
		engine_cleanup(input, tokens, cmds);
		engine_signals(envp);
	}
	engine_cleanup(input, tokens, cmds);
}
