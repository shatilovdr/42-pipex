/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:25:06 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/30 14:30:34 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_bool	paths_initialize(t_px *px, char **envp);
t_bool	cmds_initialize(t_px *px, int argc, char **argv);

t_px	*px_initialize(int argc, char **argv, char **envp)
{
	t_px	*px;

	px = (t_px *)ft_calloc(1, sizeof(t_px));
	if (!px)
	{
		ft_putendl_fd("Can't allocate memory for t_px *", 2);
		return (NULL);
	}
	if (paths_initialize(px, envp) == false)
		return (NULL);
	if (cmds_initialize(px, argc, argv) == false)
		return (NULL);
	px->pids = ft_calloc(argc - 3, sizeof(pid_t));
	if (!px->pids)
	{
		free_px(px);
		return (NULL);
	}
	return (px);
}

t_bool	paths_initialize(t_px *px, char **envp)
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
		path = "/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin";
	px->paths = ft_split(path, ':');
	if (!px->paths)
	{
		ft_putendl_fd("Can't allocate memory for px->paths", 2);
		free_px(px);
		return (false);
	}
	return (true);
}

t_bool	cmds_initialize(t_px *px, int argc, char **argv)
{
	char	**cmds;
	int		i;

	cmds = (char **)ft_calloc((argc - 3) + 1, sizeof(char *));
	if (!cmds)
	{
		free_px(px);
		ft_putendl_fd("Can't allocate memory for px->cmds", 2);
		return (false);
	}
	i = 0;
	while (i < argc - 3)
	{
		cmds[i] = ft_strdup(argv[2 + i]);
		if (!cmds[i])
		{
			ft_free_2d_array(cmds);
			free_px(px);
			ft_putendl_fd("Can't allocate memory for px->cmds", 2);
			return (false);
		}
		i++;
	}
	px->cmds = cmds;
	return (true);
}
