/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:18:29 by wdavey            #+#    #+#             */
/*   Updated: 2024/01/10 23:45:08 by wdavey           ###   ########.fr       */
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

char	*get_input(void)
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
		if (input)
			free(input);
		input = readline("minishell> ");
	}
	tcgetattr(0, &t);
	t.c_lflag = t.c_lflag | ECHOCTL;
	tcsetattr(0, TCSANOW, &t);
	return (input);
}
