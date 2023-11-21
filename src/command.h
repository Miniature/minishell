/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:00:46 by wdavey            #+#    #+#             */
/*   Updated: 2023/11/21 15:03:54 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include <sys/types.h>

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
