/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 06:40:19 by wdavey            #+#    #+#             */
/*   Updated: 2023/11/21 17:28:03 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_all(char **strs)
{
	size_t	iii;
	char	*now;

	if (strs == NULL)
		return ;
	iii = -1;
	while (strs[++iii] != NULL)
	{
		now = strs[iii];
		free(strs[iii]);
	}
	free(strs);
}
