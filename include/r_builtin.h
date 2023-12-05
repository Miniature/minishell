/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_builtin.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:55:50 by wdavey            #+#    #+#             */
/*   Updated: 2023/12/04 17:03:37 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef R_BUILTIN_H
# define R_BUILTIN_H

# include "command.h"
# include "str.h"

int		builtin_cd(t_command cmd);
int		builtin_pwd(t_command cmd);
int		builtin_echo(t_command cmd);
int		builtin_unset(t_command cmd);
void	print_echo(t_command cmd, bool n);

#endif
