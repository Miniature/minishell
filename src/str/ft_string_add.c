/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 07:35:25 by wdavey            #+#    #+#             */
/*   Updated: 2023/10/10 08:21:45 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include <stdlib.h>
#include "libftprintf.h"

t_string	*string_minsize(t_string *s, size_t min)
{
	char	*tmp;
	size_t	newsize;

	if (min < s->size)
		return (s);
	newsize = 1UL << 63;
	while (0 == (newsize & min))
		newsize = newsize >> 1;
	newsize = newsize << 1;
	tmp = s->cstr;
	s->cstr = malloc(newsize * sizeof(*(s->cstr)));
	if (NULL != tmp)
		ft_memcpy(s->cstr, tmp, s->size);
	else
		(s->cstr[0]) = '\0';
	s->size = newsize;
	return (s);
}

t_string	*string_addcstr(t_string *s, const char *s2)
{
	if (0 == s->size)
		string_minsize(s, ft_strlen(s2) + 1);
	else if (ft_strlen(s->cstr) + ft_strlen(s2) > s->size)
		string_minsize(s, ft_strlen(s->cstr) + ft_strlen(s2) + 1);
	ft_strlcat(s->cstr, s2, s->size);
	return (s);
}

t_string	*string_addchar(t_string *s, char c)
{
	if (0 == s->size)
		string_minsize(s, 2);
	else if (ft_strlen(s->cstr) + 1 >= s->size)
		string_minsize(s, s->size + 1);
	s->cstr[ft_strlen(s->cstr) + 1] = '\0';
	s->cstr[ft_strlen(s->cstr)] = c;
	return (s);
}
