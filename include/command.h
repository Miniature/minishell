/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:00:46 by wdavey            #+#    #+#             */
/*   Updated: 2023/11/21 17:33:44 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include <sys/types.h>

# define DEFAULT_PATH "PATH=/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:."

enum
{
	IN,
	OUT
};

typedef struct s_command
{
	char	**argv;
	char	**envp;
	int		fd[2];
}	t_command;

//for non-builtins
int		exec_external_command(t_command cmd);
char	*resolve_path(t_command cmd);

#endif
