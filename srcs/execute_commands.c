/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:58:49 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/28 23:17:25 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	execute_first(t_px *px, int in_fd, int pipes[2][2]);
int	execute_middle(t_px *px, int num, int pipes[2][2]);
int	execute_last(t_px *px, int pos, int out_fd, int pipes[2][2]);
int	execute_command(t_px *px, int i, int in, int out);

int	execute_commands(t_px *px, int num, char *infile, char *outfile)
{
	int	status;
	int	pipes[2][2];
	int	in_fd;
	int	out_fd;

	in_fd = open_input_file(infile);
	if (in_fd == OPEN_FAILURE)
		return (OPEN_FAILURE);
	status = execute_first(px, in_fd, pipes);
	if (status)
		return (status);
	status = execute_middle(px, num, pipes);
	if (status)
		return (status);
	out_fd = open_output_file(outfile);
	if (out_fd == OPEN_FAILURE)
	{
		close(pipes[num % 2][READ]);
		return (OPEN_FAILURE);
	}
	return (execute_last(px, num, out_fd, pipes));
}

int	execute_first(t_px *px, int in_fd, int pipes[2][2])
{
	int	status;

	if (pipe(pipes[0]) == -1)
		return (pipe_failure(in_fd));
	px->pids[0] = fork();
	if (px->pids[0] == -1)
		return (fork_failure(in_fd, pipes[0][READ], pipes[0][WRITE]));
	if (px->pids[0] == CHILD && close(pipes[0][READ] != 0))
		chld_close_failure(in_fd, pipes[0][WRITE]);
	status = execute_command(px, 0, in_fd, pipes[0][WRITE]);
	if (close(in_fd) != 0)
		return (CLOSE_FAILURE);
	return (status);
}

int	execute_middle(t_px *px, int num, int pipes[2][2])
{
	int	i;
	int	curr;
	int	prev;
	int	status;

	i = 1;
	status = 0;
	while (status == 0 && i < num - 1)
	{
		curr = i % 2;
		prev = (i - 1) % 2;
		if (pipe(pipes[curr]) == -1)
			return (pipe_failure(pipes[prev][READ]));
		px->pids[i] = fork();
		if (px->pids[i] == -1)
			return (fork_failure(pipes[prev][READ], pipes[curr][READ],
				pipes[curr][WRITE]));
		if (px->pids[i] == CHILD && close(pipes[curr][READ] != 0))
			chld_close_failure(pipes[prev][READ], pipes[curr][WRITE]);
		status = execute_command(px, i, pipes[prev][READ], pipes[curr][WRITE]);
		if (close(pipes[prev][READ]) != 0)
			return (CLOSE_FAILURE);
		i++;
	}
	return (status);
}

int	execute_last(t_px *px, int num, int out_fd, int pipes[2][2])
{
	int	status;
	int	last;

	last = num % 2;
	px->pids[num - 1] = fork();
	if (px->pids[num - 1] == -1)
	{
		close(out_fd);
		close(pipes[last][READ]);
		return (FORK_FAILURE);
	}
	status = execute_command(px, num - 1, pipes[last][READ], out_fd);
	if (close(pipes[last][READ]) != 0)
		return (CLOSE_FAILURE);
	return (status);
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
