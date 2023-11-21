/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 06:40:19 by wdavey            #+#    #+#             */
/*   Updated: 2023/10/26 16:11:59 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_free_all(char **strs)
{
	size_t	iii;
	char	*now;

	if (NULL == strs)
		return ;
	iii = -1;
	while (NULL != strs[++iii])
	{
		now = strs[iii];
		free(strs[iii]);
	}
	free(strs);
}
