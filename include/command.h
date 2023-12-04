/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:00:46 by wdavey            #+#    #+#             */
/*   Updated: 2023/12/04 19:05:35 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include <sys/types.h>

# define DEFAULT_PATH "PATH=/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:."

enum
{
	FD_IN,
	FD_OUT
};

typedef struct s_command
{
	char	**argv;
	char	***envp;
	int		fd[2];
}	t_command;

int		exec_command(t_command cmd);
int		exec_command_builtin(t_command cmd, int (*f)(t_command));
//for non-builtins
int		exec_command_external(t_command cmd);
char	*resolve_path(t_command cmd);

#endif
