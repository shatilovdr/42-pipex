/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_failures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:34:38 by dshatilo          #+#    #+#             */
/*   Updated: 2024/02/14 11:01:17 by dshatilo         ###   ########.fr       */
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

void	chld_fd_cls_fail(t_px *px, int in, int out, char **cmd)
{
	if (in != -1)
		close(in);
	if (out != -1)
		close(out);
	if (cmd)
		ft_free_2d_array(cmd);
	free_px(px);
	exit(CLOSE_FAILURE);
}

void	chld_execve_fail(t_px *px, char **cmd)
{
	ft_free_2d_array(cmd);
	free_px(px);
	exit(EXECVE_FAILURE);
}
