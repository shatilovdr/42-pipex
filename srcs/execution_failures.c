/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_failures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:34:38 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/29 19:02:18 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipe_failure(int fd_read_prev)
{
	close(fd_read_prev);
	return (PIPE_FAILURE);
}

int	fork_failure(int fd_read_prev, int fd_read, int fd_write)
{
	if (fd_read_prev > 0)
		close(fd_read_prev);
	close(fd_read);
	close(fd_write);
	return (FORK_FAILURE);
}

void	chld_close_failure(int fd_read_prev, int fd_write)
{
	close(fd_read_prev);
	close(fd_write);
	exit(CLOSE_FAILURE);
}

void	execve_failure(t_px *px, int in, int out, char **cmd)
{
	close(in);
	close(out);
	(void)px;
	(void)cmd;
	exit(EXECVE_FAILURE);
}
