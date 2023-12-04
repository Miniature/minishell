/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_builtin_pwd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:44:28 by wdavey            #+#    #+#             */
/*   Updated: 2023/12/04 17:04:57 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "r_builtin.h"

int	builtin_pwd(t_command cmd)
{
	char	*buf;

	(void)cmd;
	buf = getcwd(NULL, 0);
	if (buf != NULL)
		printf("%s\n", buf);
	else
		perror("pwd");
	free(buf);
	return (0);
}
