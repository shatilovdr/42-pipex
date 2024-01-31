/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:12:04 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/31 16:11:39 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_bool	get_command(t_px *px, int i, char ***command)
{
	char	**cmd;
	char	*c;

	c = find_executable(px->cmds[i], px->paths);
	if (!c)
		return (false);
	cmd = ft_split(px->cmds[i], ' ');
	if (!cmd)
	{
		free(c);
		ft_putstr_fd("Can't split cmd: ", 2);
		ft_putendl_fd(px->cmds[i], 2);
		return (false);
	}
	free(cmd[0]);
	cmd[0] = c;
	*command = cmd;
	return (true);
}
