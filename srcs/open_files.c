/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:29:39 by dshatilo          #+#    #+#             */
/*   Updated: 2024/02/02 14:05:11 by dshatilo         ###   ########.fr       */
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

int	open_output_file(char *location, t_bool here_doc)
{
	int	fd;
	int	status;

	status = check_access(location, 1);
	if (status != 0)
		return (status);
	if (here_doc == true)
		fd = open(location, O_CREAT | O_WRONLY | O_APPEND, 0644);
	else
		fd = open(location, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		ft_putendl_fd("Can't open output file", 2);
		return (OPEN_FAILURE);
	}
	return (fd);
}
