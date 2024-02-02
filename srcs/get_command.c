/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:12:04 by dshatilo          #+#    #+#             */
/*   Updated: 2024/02/02 17:23:17 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	args_parser(char **cmd);

int	get_command(t_px *px, int i, char ***command)
{
	char	**cmd;
	int		status;

	cmd = ft_split(px->cmds[i], ' ');
	if (!cmd)
	{
		ft_putstr_fd("Can't split cmd: ", 2);
		ft_putendl_fd(px->cmds[i], 2);
		free_px(px);
		return (MALLOC_FAILURE);
	}
	status = find_executable(&(cmd[0]), px->paths);
	if (status != 0)
	{
		ft_free_2d_array(cmd);
		free_px(px); //can't free it..?
		return (status);
	}
	status = args_parser(cmd);
	if (status != 0)
	{
		free_px(px);
		return (status);
	}
	*command = cmd;
	return (0);
}

int	args_parser(char **cmd)
{
	(void)cmd;
	return (0);
}
