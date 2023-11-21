/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 08:06:37 by wdavey            #+#    #+#             */
/*   Updated: 2023/11/21 15:45:57 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "str.h"
#include "libft.h"

t_string	string_new(void)
{
	t_string	n;

	n.cstr = NULL;
	n.size = 0;
	return (n);
}

t_string	string_new_cstr(char *cstr)
{
	t_string	n;

	n.cstr = cstr;
	n.size = ft_strlen(cstr) + 1;
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
