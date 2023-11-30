/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:26:42 by wdavey            #+#    #+#             */
/*   Updated: 2023/11/28 16:35:33 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

char	*ms_getenv(char ***envp, char *name);
void	ms_setenv(char ***envp, char *value);
void	ms_unsetenv(char*** envp, char* name);
bool	update_env(char** env, char* value, int name_length);
int		find_and_remove(char** env, char* name, int name_length);

#endif
