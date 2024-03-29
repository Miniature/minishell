/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:12:53 by wdavey            #+#    #+#             */
/*   Updated: 2024/01/09 15:58:34 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	free_all(char **strs);
char	**array_append(char ***arglist, const char *arg);
void	*array_last(void **a);

bool	ms_isspace(char c);

#endif
