#ifndef FT_R_SIGNAL_H
# define FT_R_SIGNAL_H

# include "libft.h"

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

#endif