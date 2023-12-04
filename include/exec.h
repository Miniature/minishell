/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:57:01 by wdavey            #+#    #+#             */
/*   Updated: 2023/12/04 16:58:56 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "command.h"

typedef struct s_builtin
{
	char	*name;
	int		(*function)(t_command);
}	t_builtin;

#endif
