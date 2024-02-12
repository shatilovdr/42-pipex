/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_executable_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:02:40 by dshatilo          #+#    #+#             */
/*   Updated: 2024/02/06 15:14:55 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int		check_path_provided(char *cmd_name, char **cmd_in_path);
int		find_cmd_in_path(char *cmd_name, char **paths, char **cmd_in_path);
char	*cmd_to_search(char *cmd_name, int *length, char **paths);
int		check_cmd_in_path(char **candidate, int len,
			char *cmd_name, char *path);

int	find_executable(char **command, char **paths)
{
	int		status;
	char	*cmd_in_path;

	cmd_in_path = NULL;
	if (strchr(*command, '/') == NULL)
		status = find_cmd_in_path(*command, paths, &cmd_in_path);
	else
		status = check_path_provided(*command, &cmd_in_path);
	if (status == 0)
	{
		if (strchr(*command, '/') == NULL)
			free(*command);
		*command = cmd_in_path;
	}
	else if (status == CMD_NF_FAILURE)
	{
		ft_putstr_fd("zsh: command not found: ", 2);
		ft_putendl_fd(*command, 2);
	}
	else if (status == CMD_PD_FAILURE)
	{
		ft_putstr_fd("zsh: permission denied: ", 2);
		ft_putendl_fd(*command, 2);
	}
	return (status);
}

int	check_path_provided(char *cmd_name, char **cmd_in_path)
{
	if (access(cmd_name, F_OK) != 0)
		return (CMD_NF_FAILURE);
	if (access(cmd_name, X_OK) != 0)
		return (CMD_PD_FAILURE);
	*cmd_in_path = cmd_name;
	return (0);
}

int	find_cmd_in_path(char *cmd_name, char **paths, char **cmd_in_path)
{
	int		status;
	char	*candidate;
	int		len;
	int		i;

	len = 0;
	candidate = cmd_to_search(cmd_name, &len, paths);
	if (!candidate)
		return (MALLOC_FAILURE);
	i = 0;
	while (paths[i])
	{
		status = check_cmd_in_path(&candidate, len, cmd_name, paths[i]);
		if (status != 1)
		{
			if (status == 0)
				*cmd_in_path = candidate;
			else if (status == CMD_PD_FAILURE)
				free(candidate);
			return (status);
		}
		i++;
	}
	free(candidate);
	return (CMD_NF_FAILURE);
}

char	*cmd_to_search(char *cmd_name, int *length, char **paths)
{
	char	*cmd;
	int		len;
	int		curr_len;
	int		i;

	i = 0;
	len = 0;
	while (paths[i])
	{
		curr_len = ft_strlen(paths[i]);
		if (curr_len > len)
			len = curr_len;
		i++;
	}
	len += ft_strlen(cmd_name) + 1 + 1;
	cmd = (char *)ft_calloc(len, sizeof(char));
	if (!cmd)
	{
		ft_putstr_fd("Can't start searching path for command: ", 2);
		ft_putendl_fd(cmd_name, 2);
		return (NULL);
	}
	*length = len;
	return (cmd);
}

int	check_cmd_in_path(char **candidate, int len, char *cmd_name, char *path)
{
	char	*temp;

	temp = *candidate;
	ft_memset(temp, 0, len);
	ft_strlcat(temp, path, len);
	ft_strlcat(temp, "/", len);
	ft_strlcat(temp, cmd_name, len);
	if (access(temp, F_OK) == 0)
	{
		if (access(temp, X_OK) == 0)
			return (0);
		else
			return (CMD_PD_FAILURE);
	}
	else
		return (1);
}
