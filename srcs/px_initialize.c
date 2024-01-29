/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:25:06 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/29 18:42:55 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	paths_initialize(t_px *px, char **envp);
void	cmds_initialize(t_px *px, int num);

t_px	*px_initialize(int argc, char **envp)
{
	t_px	*px;

	px = (t_px *)ft_calloc(1, sizeof(t_px));
	if (!px)
	{
		ft_putendl_fd("Can't allocate memory for t_px *", 2);
		exit(EXIT_FAILURE);
	}
	paths_initialize(px, envp);
	cmds_initialize(px, argc - 3);
	px->pids = ft_calloc(argc - 3, sizeof(pid_t));
	return (px);
}

void	paths_initialize(t_px *px, char **envp)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	while (envp[i])
	{
		if (!ft_strncmp("PATH=", envp[i], 5))
		{
			path = envp[i] + 5;
			break ;
		}
		i++;
	}
	if (!path)
		path = "/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:.";
	px->paths = ft_split(path, ':');
	if (!px->paths)
	{
		ft_putendl_fd("Can't allocate memory for px->paths", 2);
		free(px);
		exit(EXIT_FAILURE);
	}
}

void	cmds_initialize(t_px *px, int num)
{
	(void)px;
	(void)num;
}