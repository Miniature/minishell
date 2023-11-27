/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_builtin_cd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:37:29 by wdavey            #+#    #+#             */
/*   Updated: 2023/11/27 18:41:40 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "r_builtin.h"

void	builtin_cd(char *path)
{
	if (path == NULL)
	{
		path = getenv("HOME");
	}
	else if (!strcmp(path, "-"))
	{
		path = getenv("OLDPWD");
		printf("%s\n", path);
	}
	if (chdir(path) != 0)
	{
		perror("cd");
	}
}
