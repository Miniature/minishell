/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 08:06:37 by wdavey            #+#    #+#             */
/*   Updated: 2023/10/10 08:08:07 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_string.h"

t_string	string_new(void)
{
	t_string	n;

	n.cstr = NULL;
	n.size = 0;
	return (n);
}

t_string	*string_del(t_string *s)
{
	if (0 != s->size)
		free(s->cstr);
	s->cstr = NULL;
	s->size = 0;
	return (s);
}

char	*string_pop(t_string *s)
{
	char	*cstr;

	cstr = s->cstr;
	s->cstr = NULL;
	s->size = 0;
	return (cstr);
}
