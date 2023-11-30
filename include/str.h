/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:45:23 by wdavey            #+#    #+#             */
/*   Updated: 2023/11/21 16:03:16 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

# include <stdbool.h>
# include <stddef.h>

typedef struct s_string {
	char	*cstr;
	size_t	size;
}	t_string;

int			ft_strncasecmp(char* s1, char* s2, int n);
t_string	string_new(void);
t_string	string_new_cstr(char *cstr);
t_string	*string_del(t_string *s);
char		*string_pop(t_string *s);

t_string	*string_addcstr(t_string *s, const char *s2);
t_string	*string_addchar(t_string *s, char c);
int			ft_strcmp(const char *s1, const char *s2);
bool		ft_strnequ(const char* s1, const char* s2, size_t n);
bool		str_has_any(char *str, bool(*f)(char));
bool		str_has_any_char(char *str, char c);
bool		str_has_all(char *str, bool(*f)(char));

#endif
