/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:47:41 by wdavey            #+#    #+#             */
/*   Updated: 2024/01/09 16:09:24 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include <stddef.h>
#include <stdlib.h>
#include "libft.h"
#include "str.h"
#include "env.h"
#include "utils.h"
#include <unistd.h>

bool	is_meta_char(char c);

static size_t	single_quote(char *str, t_string *current)
{
	if (ft_strchr(str + 1, '\''))
		*ft_strchr(str + 1, '\'') = '\0';
	string_addcstr(current, str + 1);
	return (ft_strlen(str));
}

static size_t	insert_env(char *str, char ***envp, t_string *current)
{
	t_string	name;
	size_t		rval;
	char		*var;

	if (*str == '?')
	{
		if (ms_getenv_value(envp, "?") != NULL)
			string_addcstr(current, ms_getenv_value(envp, "?"));
		else
			string_addcstr(current, "0");
		return (1);
	}
	name = (t_string){ft_strdup(""), 1};
	while (ft_isalnum(str[ft_strlen(name.cstr)]))
		string_addchar(&name, str[ft_strlen(name.cstr)]);
	var = ms_getenv(envp, name.cstr);
	if (var)
		string_addcstr(current, ms_getenv_value(envp, name.cstr));
	rval = ft_strlen(name.cstr);
	string_del(&name);
	return (rval);
}

static size_t	tokenize_step(char *str, char ***arglist, t_string *current)
{
	size_t		iii;
	static bool	in_quote;

	if (str[0] == '"')
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

#define NOHOME "minishell: HOME is not defined\n"

static size_t	home(char *str, t_string *current, char ***envp)
{
	char	*value;

	if ('\0' != str[1] && ' ' != str[1])
	{
		string_addchar(current, '~');
	}
	else
	{
		value = ms_getenv_value(envp, "HOME");
		if (NULL == value)
		{
			write(STDERR_FILENO, NOHOME, ft_strlen(NOHOME));
			string_addchar(current, '~');
		}
		else
			string_addcstr(current, value);
	}
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
		if (str[iii] == '\'')
			iii += single_quote(str + iii, &arg);
		else if (str[iii] == '$')
			iii += insert_env(str + iii + 1, envp, &arg);
		else if ('~' == str[iii] && (0 == iii || ' ' == str[iii - 1]))
			iii += home(str + iii, &arg, envp);
		else
			iii += tokenize_step(str + iii, &arglist, &arg);
	}
	if (arg.cstr)
		array_append(&arglist, string_pop(&arg));
	return (arglist);
}
