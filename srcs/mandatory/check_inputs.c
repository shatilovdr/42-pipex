/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:03:37 by dshatilo          #+#    #+#             */
/*   Updated: 2024/02/03 12:57:33 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_bool	check_inputs(int argc)
{
	if (argc != 5)
	{
		ft_putendl_fd("INCORRECT NUMBER OF ARGUMENTS!\n"
			"example: file1 cmd1 cmd2 file2", 2);
		return (false);
	}
	return (true);
}
