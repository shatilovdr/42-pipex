/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_executable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:02:40 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/31 14:32:40 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_path_provided(char *command);
char	*find_cmd_in_path(char *cmd_name, char **paths);
int		check_cmd_in_path(
			char **cmd_in_path, int len, char *cmd_name, char *path);
int		max_path_len(char **paths);

char	*find_executable(char *command, char **paths)
{
	int		i;
	char	*cmd_name;
	char	*cmd_in_path;

	i = 0;
	while (command[i] != 0 && command[i] != ' ')
		i++;
	cmd_name = ft_substr(command, 0, i);
	if (!cmd_name)
	{
		ft_putstr_fd("Can't start searching for: ", 2);
		ft_putendl_fd(command, 2);
		return (NULL);
	}
	if (strchr(cmd_name, '/') != NULL)
		cmd_in_path = check_path_provided(cmd_name);
	else
	{
		cmd_in_path = find_cmd_in_path(cmd_name, paths);
		free(cmd_name);
	}
	return (cmd_in_path);
}

char	*check_path_provided(char *cmd_name)
{
	if (access(cmd_name, F_OK) != 0)
	{
		ft_putstr_fd("zsh: command not found: ", 2);
		ft_putendl_fd(cmd_name, 2);
		free(cmd_name);
		return (NULL);
	}
	if (access(cmd_name, X_OK) != 0)
	{
		ft_putstr_fd("zsh: permission denied: ", 2);
		ft_putendl_fd(cmd_name, 2);
		free(cmd_name);
		return (NULL);
	}
	return (cmd_name);
}

char	*find_cmd_in_path(char *cmd_name, char **paths)
{
	char	*cmd_in_path;
	int		len;
	int		i;
	int		status;

	len = max_path_len(paths) + 1 + ft_strlen(cmd_name) + 1;
	cmd_in_path = (char *)ft_calloc(len, sizeof(char));
	if (!cmd_in_path)
	{
		ft_putstr_fd("Can't start searching path for command: ", 2);
		ft_putendl_fd(cmd_name, 2);
		return (NULL);
	}
	i = 0;
	while (paths[i])
	{
		status = check_cmd_in_path(&cmd_in_path, len, cmd_name, paths[i]);
		if (status == 0 || status == -1)
			return (cmd_in_path);
		i++;
	}
	free(cmd_in_path);
	ft_putstr_fd("zsh: command not found: ", 2);
	ft_putendl_fd(cmd_name, 2);
	return (NULL);
}

int	check_cmd_in_path(char **cmd_in_path, int len, char *cmd_name, char *path)
{
	char	*temp;

	temp = *cmd_in_path;
	ft_memset(temp, 0, len);
	ft_strlcat(temp, path, len);
	ft_strlcat(temp, "/", len);
	ft_strlcat(temp, cmd_name, len);
	if (access(temp, F_OK) == 0)
	{
		if (access(temp, X_OK) != 0)
		{
			ft_putstr_fd("zsh: permission denied: ", 2);
			ft_putendl_fd(temp, 2);
			free(temp);
			*cmd_in_path = NULL;
			return (-1);
		}
		return (0);
	}
	else
		return (1);
}

int	max_path_len(char **paths)
{
	int	i;
	int	len;
	int	curr_len;

	i = 0;
	len = 0;
	while (paths[i])
	{
		curr_len = ft_strlen(paths[i]);
		if (curr_len > len)
			len = curr_len;
		i++;
	}
	return (len);
}
