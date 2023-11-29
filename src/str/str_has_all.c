/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_has_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:11:38 by wdavey            #+#    #+#             */
/*   Updated: 2023/09/11 16:34:20 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	str_has_all(char *str, bool(*f)(char))
{
	while (*str)
	{
		if (!f(*str))
			return (false);
		str++;
	}
	return (true);
}

bool	ft_strnequ(const char* s1, const char* s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	if (!ft_strncmp(s1, s2, n))
		return (1);
	return (0);
}