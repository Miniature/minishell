/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_has_any.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:11:38 by wdavey            #+#    #+#             */
/*   Updated: 2023/12/04 16:52:22 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

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

int	ft_strncasecmp(char *s1, char *s2, int n)
{
	if (n == 0)
		return (0);
	while (n-- != 0 && ft_tolower(*s1) == ft_tolower(*s2))
	{
		if (n == 0 || *s1 == '\0' || *s2 == '\0')
			break ;
		s1++;
		s2++;
	}
	return (ft_tolower(*(unsigned char *)s1)
		- ft_tolower(*(unsigned char *)s2));
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
