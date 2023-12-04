/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_builtin_unset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:34:09 by wdavey            #+#    #+#             */
/*   Updated: 2023/12/04 19:36:47 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r_builtin.h"
#include "libft.h"
#include "str.h"
#include "env.h"

int	builtin_unset(t_command cmd)
{
	int		i;
	int		name_length;
	char	*name;
	char	**env;

	env = *(cmd.envp);
	name = cmd.argv[1];
	name_length = ft_strlen(name);
	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], name, name_length) == 0
			&& env[i][name_length] == '=')
		{
			ms_unsetenv(env, name);
			break ;
		}
		i++;
	}
	return (0);
}
