/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:45:23 by wdavey            #+#    #+#             */
/*   Updated: 2023/11/21 15:10:47 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

# include <stdbool.h>

bool	str_has_any(char *str, bool(*f)(char));
bool	str_has_any_char(char *str, char c);
bool	str_has_all(char *str, bool(*f)(char));

#endif
