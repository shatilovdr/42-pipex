/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:03:37 by dshatilo          #+#    #+#             */
/*   Updated: 2024/02/03 13:53:58 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_bool	check_inputs(int argc, char **argv, t_bool *here_doc)
{
	if (argc < 5)
	{
		ft_putendl_fd("NOT ENOUGH ARGUMENTS!\n"
			"example: file1 cmd1 cmd2 file2", 2);
		return (false);
	}
	*here_doc = (ft_strncmp("here_doc", argv[1], 9) == 0);
	if (*here_doc == true && argc < 6)
	{
		ft_putendl_fd("NOT ENOUGH ARGUMENTS FOR HERE_DOC!\n"
			"example: here_doc LIMITER cmd1 cmd2 file", 2);
		return (false);
	}
	return (true);
}
