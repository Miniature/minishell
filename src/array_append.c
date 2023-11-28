/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_append.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:17:25 by wdavey            #+#    #+#             */
/*   Updated: 2023/11/28 18:18:16 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

static char	**array_append(char ***arglist, const char *arg)
{
	size_t	listsize;
	char	**newlist;

	listsize = 0;
	while (NULL != (*arglist)[listsize])
		listsize++;
	newlist = malloc((listsize + 2) * (sizeof(**arglist)));
	ft_memcpy(newlist, *arglist, listsize * sizeof(**arglist));
	newlist[listsize] = (char *)arg;
	newlist[listsize + 1] = NULL;
	free(*arglist);
	*arglist = newlist;
	return (newlist);
}
