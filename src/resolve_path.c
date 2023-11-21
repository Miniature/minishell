/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:04:05 by wdavey            #+#    #+#             */
/*   Updated: 2023/11/21 15:49:19 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "command.h"
#include "libft.h"
#include "str.h"

char	*resolve_path(t_command cmd)
{
	t_string	str;

	if ('/' == cmd.argv[0][0])
		return (ft_strdup(cmd.argv[0]));
	else if (str_has_any_char(cmd.argv[0], '/'))
	{
		str = string_new_cstr(getcwd(NULL, -1));
		return (string_addcstr(&str, cmd.argv[0])->cstr);
	}
	else
	{
		//todo
		return (ft_strdup(cmd.argv[0]));
	}
}
