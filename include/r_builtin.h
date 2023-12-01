/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_builtin.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:55:50 by wdavey            #+#    #+#             */
/*   Updated: 2023/11/27 19:20:51 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef R_BUILTIN_H
# define R_BUILTIN_H

# include "command.h"
# include "str.h"

int		builtin_cd(t_command cmd);
void	builtin_pwd();
int		builtin_echo(char **args);
void	print_echo(char **args, bool n);

#endif
