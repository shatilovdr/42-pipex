/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:29:39 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/27 20:04:02 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_input_file(char *location)
{
	int		fd;

	if (check_access(location, 0) == -1)
		return (-1);
	fd = open(location, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Can't open file", 2);
		return (-2);
	}
	return (fd);
}

int	open_output_file(char *location)
{
	int		fd;

	if (check_access(location, 1) == -1)
		return (-1);
	fd = open(location, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		ft_putendl_fd("Can't open file", 2);
		return (-2);
	}
	return (fd);
}