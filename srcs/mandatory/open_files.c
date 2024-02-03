/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:29:39 by dshatilo          #+#    #+#             */
/*   Updated: 2024/02/03 12:58:13 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_input_file(char *location)
{
	int	fd;
	int	status;

	status = check_access(location, 0);
	if (status != 0)
		return (status);
	fd = open(location, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Can't open input file", 2);
		return (OPEN_FAILURE);
	}
	return (fd);
}

int	open_output_file(char *location)
{
	int	fd;
	int	status;

	status = check_access(location, 1);
	if (status != 0)
		return (status);
	fd = open(location, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		ft_putendl_fd("Can't open output file", 2);
		return (OPEN_FAILURE);
	}
	return (fd);
}
