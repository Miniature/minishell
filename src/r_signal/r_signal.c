#include "r_signal.h"

//t_signal	g_signal;

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
	g_signal.signal = _SIGOKAY;
	g_signal.pid = 0;
}

void	signal_handler(int input_code)
{
	if (input_code == SIGINT)
	{
		write(STDERR_FILENO, "\n", 1);
		rl_replaceline("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_signal.signal = _SIGINTERUPT;
	}
}
