/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_signal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:48:52 by wdavey            #+#    #+#             */
/*   Updated: 2024/01/10 23:31:10 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef R_SIGNAL_H
# define R_SIGNAL_H

# include "libft.h"
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

extern int	g_signal;

typedef enum e_signalStatus
{
	_SIGOKAY,
	_SIGINTERUPT,
	_SIGEXIT,
	_SIGEOF
}	t_signalStatus;

typedef struct s_signal
{
	t_signalStatus			signal;
	pid_t					pid;
	int						exit_code;
}	t_signal;

void	signal_init(void);
void	signal_handler(int input_code);
void	ignore(int a);

#endif
