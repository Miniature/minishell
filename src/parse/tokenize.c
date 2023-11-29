/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:47:41 by wdavey            #+#    #+#             */
/*   Updated: 2023/11/29 16:36:02 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include <stddef.h>
#include <stdlib.h>
#include "libft.h"
#include "str.h"
#include "env.h"

char	**array_append(char ***arglist, const char *arg);

static size_t	single_quote(char *str, t_string *current)
{
	if (ft_strchr(str + 1, '\''))
		*ft_strchr(str + 1, '\'') = '\0';
	string_addcstr(current, str);
	return (ft_strlen(str));
}

static size_t	insert_env(char *str, char ***envp, t_string *current)
{
	t_string	name;
	size_t		rval;

	if ('?' == *str)
	{
		name.cstr = ft_itoa(0/* todo: replace with exit code */);
		string_addcstr(current, name.cstr);
		free(name.cstr);
		return (1);
	}
	name = string_new();
	while (ft_isalnum(str[ft_strlen(name.cstr)]))
		string_addchar(&name, str[ft_strlen(name.cstr)]);
	string_addcstr(current, ms_getenv(envp, name.cstr)
		+ ft_strlen(name.cstr) + 1);
	rval = ft_strlen(name.cstr);
	string_del(&name);
	return (rval);
}

bool	is_meta_char(char c)
{
	return (
		c == ' '
		|| c == '>'
		|| c == '<'
		|| c == '|'
	);
}

static size_t	tokenize_step(char *str, char ***arglist, t_string *current)
{
	size_t		iii;
	static bool	in_quote;

	if ('"' == str[0])
		in_quote = !in_quote;
	else if (!in_quote && is_meta_char(str[0]))
	{
		iii = 0;
		*arglist = array_append(arglist, string_pop(current));
		while (is_meta_char(str[iii]))
		{
			if (str[iii] != ' ')
				string_addchar(current, str[iii]);
			else if (current->size && ft_strlen(current->cstr))
				*arglist = array_append(arglist, string_pop(current));
			iii++;
		}
		if (current->size && ft_strlen(current->cstr))
			*arglist = array_append(arglist, string_pop(current));
		return (iii - 1);
	}
	else
		string_addchar(current, str[0]);
	return (0);
}

char	**tokenize_input(char *str, char ***envp)
{
	char		**arglist;
	t_string	arg;
	size_t		iii;

	arglist = ft_calloc(1, sizeof(*arglist));
	arg = string_new();
	iii = -1;
	while (str[++iii])
	{
		if ('\'' == str[iii])
			iii += single_quote(str + iii, &arg);
		else if ('$' == str[iii])
			iii += insert_env(str + iii + 1, envp, &arg);
		else
			iii += tokenize_step(str + iii, &arglist, &arg);
	}
	if (arg.cstr)
		array_append(&arglist, string_pop(&arg));
	return (arglist);
}