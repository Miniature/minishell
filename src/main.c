/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:10:56 by wdavey            #+#    #+#             */
/*   Updated: 2023/11/20 15:23:59 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "r_signal.h"

t_signal	g_signal;

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	(void)envp;
	char buf[129];
	buf[read(0, buf, 128)] = 0;
		printf("minshell: %s\n", buf);
	while (g_signal.exit_code == 0)
	{
		signal(SIGINT, &signal_handler);
		signal(SIGQUIT, &signal_handler);
	}
	return (0);
}
