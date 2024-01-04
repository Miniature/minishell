/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_signal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:45:37 by wdavey            #+#    #+#             */
/*   Updated: 2023/12/04 16:52:45 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r_signal.h"
#include <unistd.h>

int	g_signal;

//move to libft
void	*ft_memdel(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
	return (NULL);
}

void	signal_init(void)
{
	g_signal = _SIGOKAY;
}

void	signal_handler(int input_code)
{
	if (input_code == SIGINT)
	{
		write(STDERR_FILENO, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_signal = _SIGINTERUPT;
	}
	else if (input_code == SIGQUIT)
	{
		g_signal = _SIGEXIT;
	}
}
