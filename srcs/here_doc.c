/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 22:45:53 by dshatilo          #+#    #+#             */
/*   Updated: 2024/02/01 18:24:46 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_bool	read_stdin_write_to_file(int fd, char ***argv);

t_bool	ft_heredoc(int *argc, char ***argv)
{
	int		fd;
	t_bool	status;

	//check_args_num;
		//return (false);
	fd = open(".here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		ft_putendl_fd("Can't execute here_doc part", 2);
		return (false);
	}
	status = read_stdin_write_to_file(fd, argv);
	if (status == false)
	{
		ft_putendl_fd("Can't execute here_doc part", 2);
		unlink(".here_doc");
		close(fd);
	}
	if (close(fd) != 0)
	{
		unlink(".here_doc");
		status = false;
	}
	return (status);
}

t_bool	read_stdin_write_to_file(int fd, char ***argv)
{
	char	*limiter;
	char	*curr_str;

	limiter = ft_strjoin((*argv)[2], "\n");
	if (!limiter)
		return (false);
	curr_str = "\0";
	while (ft_strncmp(limiter, curr_str, ft_strlen(limiter)) != 0)
	{
		curr_str = get_next_line(0);
		if (!curr_str)
		{
			free(limiter);
			return (false);
		}
		if (write(fd, curr_str, ft_strlen(curr_str)) == -1)
		{
			free(curr_str);
			free(limiter);
			return (false);
		}
		free(curr_str);
	}
	free(limiter);
	return (true);
}


t_bool	read_stdin_write_to_file(int fd, char ***argv)
{
	char	*limiter;
	char	*curr_str;

	limiter = ft_strjoin((*argv)[2], "\n");
	if (!limiter)
		return (false);
	curr_str = "\0";
	while (ft_strncmp(limiter, curr_str, ft_strlen(limiter)) != 0)
	{
		curr_str = get_next_line(0);
		if (!curr_str)
		{
			free(limiter);
			return (false);
		}
		if (write(fd, curr_str, ft_strlen(curr_str)) == -1)
		{
			free(curr_str);
			free(limiter);
			return (false);
		}
		free(curr_str);
	}
	free(limiter);
	return (true);
}
