#ifndef FT_R_SIGNAL_H
# define FT_R_SIGNAL_H

# include "libft.h"
# include <signal.h>

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
	int						pid;
	int						exit_code;
}	t_signal;


void	signal_init(void);
void	signal_handler(int input_code);

#endif