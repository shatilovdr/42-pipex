/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:58:49 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/28 20:49:03 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	execute_first(t_px *px, int in_fd);
int	execute_last(t_px *px, int pos, int out_fd);
int	execute_command(t_px *px, int i, int in, int out);

int	execute_commands(t_px *px, int num)
{
	(void)num;
	int	status;
	int	in_fd;
	int	out_fd;

	in_fd = open_input_file(px->in_flie);
	if (in_fd == OPEN_FAILURE)
		return (OPEN_FAILURE);
	if (pipe(px->pipes[0]) == -1)
	{
		close(in_fd);
		return (PIPE_FAILURE);
	}
	status = execute_first(px, in_fd);
	if (status)
		return (status);
	out_fd = open_output_file(px->out_file);
	if (out_fd == OPEN_FAILURE)
	{
		close(px->pipes[0][READ]);
		return (OPEN_FAILURE);
	}
	return (execute_last(px, 1, out_fd));
}

int	execute_first(t_px *px, int in_fd)
{
	int	ex_status;

	px->pids[0] = fork();
	if (px->pids[0] == -1)
	{
		close(in_fd);
		close(px->pipes[0][READ]);
		close(px->pipes[0][WRITE]);
		return (FORK_FAILURE);
	}
	if (px->pids[0] == CHILD && close(px->pipes[0][READ] != 0))
	{
		close(in_fd);
		close(px->pipes[0][WRITE]);
		exit(CLOSE_FAILURE);
	}
	ex_status = execute_command(px, 0, in_fd, px->pipes[0][WRITE]);
	if (close(in_fd) != 0)
		return (CLOSE_FAILURE);
	return (ex_status);
}

int	execute_last(t_px *px, int pos, int out_fd)
{
	int	ex_status;

	px->pids[pos] = fork();
	if (px->pids[pos] == -1)
	{
		close(out_fd);
		close(px->pipes[pos][READ]);
		return (FORK_FAILURE);
	}
	ex_status = execute_command(px, pos, px->pipes[pos - 1][READ], out_fd);
	if (close(px->pipes[pos - 1][READ]) != 0)
		return (CLOSE_FAILURE);
	return (ex_status);
}

int	execute_command(t_px *px, int i, int in, int out)
{
	if (px->pids[i] == CHILD)
	{
		if (dup2(in, STDIN_FILENO) != -1 && dup2(out, STDOUT_FILENO) != -1)
		{
			if (close(in) != 0)
			{
				close(out);
				exit(CLOSE_FAILURE);
			}
			if (close(out) != 0)
				exit(CLOSE_FAILURE);
			execve(px->cmds[i][0], px->cmds[i], px->envp);
		}
		close(in);
		close(out);
		exit(1);
	}
	else
	{
		if (close(out) != 0)
			return (CLOSE_FAILURE);
	}
	return (0);
}
