/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:12:04 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/30 19:05:10 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_executable(char *cmd, char **paths);
int		max_path_len(char **paths);
t_bool	check_cmd(char *exe, int len, char *cmd, char **paths);

t_bool	find_cmd(t_px *px, int i, char ***cmd)
{
	char	**temp_cmd;
	char	*temp_c;

	temp_cmd = ft_split(px->cmds[i], ' ');
	if (!temp_cmd)
	{
		ft_putstr_fd("Can't split cmd: ", 2);
		ft_putendl_fd(px->cmds[i], 2);
		return (false);
	}
	temp_c = find_executable(temp_cmd[0], px->paths);
	if (!temp_c)
	{
		ft_free_2d_array(temp_cmd);
		return (false);
	}
	free(temp_cmd[0]);
	temp_cmd[0] = temp_c;
	*cmd = temp_cmd;
	return (true);
}

char	*find_executable(char *cmd, char **paths)
{
	char	*exe;
	int		len;

	len = max_path_len(paths) + 1 + ft_strlen(cmd) + 1;
	exe = (char *)ft_calloc(len, sizeof(char));
	if (!exe)
	{
		ft_putstr_fd("Can't start searching command: ", 2);
		ft_putendl_fd(cmd, 2);
		return (NULL);
	}
	if (ft_strchr(cmd, '/') != NULL)
	{
		if (access(cmd, F_OK) != 0)
		{
			ft_putstr_fd("zsh: command not found: ", 2);
			ft_putendl_fd(cmd, 2);
			free(exe);
			return (NULL);
		}
		if (access(cmd, X_OK) != 0)
		{
			ft_putstr_fd("zsh: permission denied: ", 2);
			ft_putendl_fd(cmd, 2);
			free(exe);
			return (NULL);
		}
		ft_strlcat(exe, cmd, len);
		return (exe);
	}
	if (check_cmd(exe, len, cmd, paths) == true)
		return (exe);
	free(exe);
	return (NULL);
}

int	max_path_len(char **paths)
{
	int	i;
	int	len;
	int	temp;

	i = 0;
	len = 0;
	while (paths[i])
	{
		temp = ft_strlen(paths[i]);
		if (temp > len)
			len = temp;
		i++;
	}
	return (len);
}

t_bool	check_cmd(char *exe, int len, char *cmd, char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		ft_memset(exe, 0, len);
		ft_strlcat(exe, paths[i], len);
		ft_strlcat(exe, "/", len);
		ft_strlcat(exe, cmd, len);
		if (access(exe, F_OK) != 0)
		{
			i++;
			continue ;
		}
		if (access(exe, X_OK) != 0)
		{
			ft_putstr_fd("zsh: permission denied: ", 2);
			ft_putendl_fd(cmd, 2);
			return (false);
		}
		return (true);
	}
	ft_putstr_fd("zsh: command not found: ", 2);
	ft_putendl_fd(cmd, 2);
	return (false);
}
