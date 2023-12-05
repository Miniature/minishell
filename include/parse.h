/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:09:14 by wdavey            #+#    #+#             */
/*   Updated: 2023/12/05 16:32:54 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stddef.h>
# include "command.h"
# include "libft.h"

typedef struct s_token_action
{
	char	*token;
	size_t	(*action)(char **, t_command *);
}	t_token_action;

char	**tokenize_input(char *str, char ***envp);
t_list	*build_commands(char **tokens, char ***envp);

size_t	token_1gt(char **args, t_command *command);
size_t	token_2gt(char **args, t_command *command);
size_t	token_1lt(char **args, t_command *command);
size_t	token_2lt(char **args, t_command *command);

#endif
