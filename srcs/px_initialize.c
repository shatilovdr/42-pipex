/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:25:06 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/28 22:47:37 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	paths_initialize(t_px *px, char **envp);
// void	pipes_initialize(t_px *px, int num);
// void	cmds_initialize(t_px *px, int num);

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
	// pipes_initialize(px, argc - 4);
	// cmds_initialize(px, argc - 3);
	(void)argc;
	px->pids = ft_calloc(100, sizeof(pid_t));
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

// void	pipes_initialize(t_px *px, int num)
// {
// 	int	i;

// 	px->pipes = (int **)ft_calloc(num + 1, sizeof(int *));
// 	if (!px->pipes)
// 	{
// 		ft_free_2d_array(px->paths);
// 		free(px);
// 		ft_putendl_fd("Can't allocate memory for px->pipes!!!", 2);
// 		exit(EXIT_FAILURE);
// 	}
// 	i = 0;
// 	while (i < num)
// 	{
// 		px->pipes[i] = (int *)malloc(2 * sizeof(int));
// 		if (!px->pipes[i])
// 		{
// 			ft_free_2d_array(px->pipes);
// 			ft_free_2d_array(px->paths);
// 			free(px);
// 			ft_putendl_fd("Can't allocate memory for px->pipes", 2);
// 			exit(EXIT_FAILURE);
// 		}
// 		i++;
// 	}
// }

// void	cmds_initialize(t_px *px, int num)
// {
// 	px->cmds = (int **)ft_calloc(num + 1, sizeof(int *));
// 	if (!px->cmds)
// 	{
// 		ft_free_2d_array(px->paths);
// 		ft_free_2d_array(px->pipes);
// 		free(px);
// 		ft_putendl_fd("Can't allocate memory for px->cmds!!!", 2);
// 		exit(EXIT_FAILURE);
// 	}
// }
