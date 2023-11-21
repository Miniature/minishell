/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_has_any.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:11:38 by wdavey            #+#    #+#             */
/*   Updated: 2023/11/21 15:10:33 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	str_has_any(char *str, bool(*f)(char))
{
	while (*str)
	{
		if (f(*str))
			return (true);
		str++;
	}
	return (false);
}

bool	str_has_any_char(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (true);
		str++;
	}
	return (false);
}
