/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:04:05 by wdavey            #+#    #+#             */
/*   Updated: 2023/11/21 15:37:32 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "command.h"
#include "libft.h"
#include "str.h"

char	*resolve_path(t_command cmd)
{
	char	*buf[2];
	size_t	iii;

	if ('/' == cmd.argv[0][0])
		return (ft_strdup(cmd.argv[0]));
	else if (str_has_any_char(cmd.argv[0], '/'))
	{
		buf[0] = getcwd(NULL, -1);
		buff[1] = ft_strjoin(get
		return (ft_strjoin(getcwd(NULL, -1), cmd.argv[0]));
	}
}
