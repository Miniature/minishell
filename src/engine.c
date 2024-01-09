/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:33:09 by wdavey            #+#    #+#             */
/*   Updated: 2024/01/09 15:58:17 by wdavey           ###   ########.fr       */
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
#include <termios.h>
#include <unistd.h>

static char	*get_input(void)
{
	char			*input;
	struct termios	t;

	tcgetattr(0, &t);
	t.c_lflag = t.c_lflag & ~ECHOCTL;
	tcsetattr(0, TCSANOW, &t);
	input = ft_strdup("");
	while (input != NULL && (ft_strlen(input) == 0
			|| str_has_all(input, ms_isspace)))
	{
		input = readline("minishell> ");
	}
	tcgetattr(0, &t);
	t.c_lflag = t.c_lflag | ECHOCTL;
	tcsetattr(0, TCSANOW, &t);
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

static void	engine_cleanup(char *input, char **tokens, t_list *cmds,
	char ***envp)
{
	if (input != NULL)
	{
		free(input);
		free_all(tokens);
		ft_lstclear(&cmds, (void (*)(void *)) & command_free);
	}
	if (envp != NULL && g_signal == _SIGEXIT)
	{
		printf("Quit: %s\n", ms_getenv_value(envp, "?"));
	}
	g_signal = _SIGOKAY;
}

static bool	engine_isexit(t_command *cmd, int *rval_loc)
{
	if (!ft_strncmp(cmd->argv[0], "exit", -1))
	{
		if (cmd->argv[1] == NULL)
			return (true);
		if (cmd->argv[2] == NULL
			&& str_has_all(cmd->argv[1], (bool (*)(char))&ft_isalnum)
			&& !str_has_any(cmd->argv[1], (bool (*)(char))&ft_isalpha))
		{
			*rval_loc = ft_atoi(cmd->argv[1]);
			return (true);
		}
	}
	return (false);
}

int	engine(char ***envp)
{
	char			*input;
	char			**tokens;
	t_list			*cmds;
	int				rval;

	rval = 0;
	while (true)
	{
		signal(SIGQUIT, SIG_IGN);
		input = get_input();
		if (input == NULL || g_signal == _SIGEXIT)
			break ;
		add_history(input);
		g_signal = _SIGOKAY;
		signal(SIGQUIT, &signal_handler);
		tokens = tokenize_input(input, envp);
		cmds = build_commands(tokens, envp);
		if (cmds && !cmds->next
			&& engine_isexit((t_command *)cmds->content, &rval))
			break ;
		engine_run(cmds, envp);
		engine_cleanup(input, tokens, cmds, envp);
	}
	engine_cleanup(input, tokens, cmds, NULL);
	return (rval);
}
