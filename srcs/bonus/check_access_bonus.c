/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 23:10:58 by dshatilo          #+#    #+#             */
/*   Updated: 2024/02/03 13:53:53 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	check_directory_and_file(char *path, char *filename_start, int mode);
int	check_directory_access(char *path, int mode);
int	check_file_access(char *filename, int path_status, int mode);

/*
* int	check_access(char *location, int mode)
* location - path to file + filename
* mode values: 0 - read, 1 - write
* Return values:
* 0 - access to directory/file and rights are granted
* NSFD - no such file or directory
* PD - permission denied
*/
int	check_access(char *location, int mode)
{
	char	*path_end;
	char	*filename;

	path_end = ft_strrchr(location, '/');
	if (path_end == NULL)
		return (check_file_access(location, 0, mode));
	else
	{
		if (path_end == location)
		{
			if (mode == 0)
				return (check_file_access(location, 0, mode));
			ft_putstr_fd("zsh: read-only file system: ", 2);
			ft_putendl_fd(location, 2);
			return (PD);
		}
		filename = path_end + 1;
		if (filename == NULL)
			return (check_directory_access(location, mode));
		else
		{
			*path_end = '\0';
			return (check_directory_and_file(location, path_end, mode));
		}
	}
}

int	check_directory_and_file(char *path, char *path_end, int mode)
{
	int		path_status;

	path_status = check_directory_access(path, mode);
	*path_end = '/';
	return (check_file_access(path, path_status, mode));
}

/*
* int	check_directory_access(char *path, int mode)
* Return values:
* 0 - access to directory and rights are granted
* NSFD - no such file or directory
* PD - permission denied
*/
int	check_directory_access(char *path, int mode)
{
	if (access(path, F_OK) != 0)
		return (NSFD);
	else if ((mode == 0 && access(path, R_OK) != 0)
		|| (mode == 1 && access(path, W_OK) != 0))
		return (PD);
	return (0);
}

/*
* int	check_file_access(char *filename, int path_status, int mode)
* Return values:
* 0 - access to file and rights are granted
* NSFD - no such file or directory
* PD - permission denied
*/
int	check_file_access(char *filename, int path_status, int mode)
{
	if (path_status == 0)
	{
		if ((mode == 0 && access(filename, F_OK | R_OK) == 0)
			|| (mode == 1 && access(filename, F_OK | W_OK) == 0)
			|| (mode == 1 && access(filename, F_OK) != 0))
			return (0);
		else if (access(filename, F_OK) == 0
			&& ((mode == 0 && access(filename, R_OK) != 0)
				|| (mode == 1 && access(filename, W_OK) != 0)))
		{
			ft_putstr_fd("zsh: permission denied: ", 2);
			ft_putendl_fd(filename, 2);
			return (PD);
		}
	}
	if (path_status == 2)
	{
		ft_putstr_fd("zsh: permission denied: ", 2);
		ft_putendl_fd(filename, 2);
		return (PD);
	}
	ft_putstr_fd("zsh: no such file or directory: ", 2);
	ft_putendl_fd(filename, 2);
	return (NSFD);
}
