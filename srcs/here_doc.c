/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 22:45:53 by dshatilo          #+#    #+#             */
/*   Updated: 2024/02/02 12:46:18 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_bool	read_stdin_write_to_file(int fd, char *limiter);

t_bool	ft_heredoc(char ***argv)
{
	int		fd;
	char	*limiter;

	limiter = ft_strjoin((*argv)[2], "\n");
	if (!limiter)
		return (false);
	fd = open(".here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		free(limiter);
		return (false);
	}
	if (ft_printf("pipe heredoc> ") == -1
		|| read_stdin_write_to_file(fd, limiter) == false)
	{
		close(fd);
		unlink(".here_doc");
		return (false);
	}
	if (close(fd) != 0)
	{
		unlink(".here_doc");
		return (false);
	}
	return (true);
}

t_bool	read_stdin_write_to_file(int fd, char *limiter)
{
	char	*curr_str;

	while (true)
	{
		curr_str = get_next_line(0);
		if (!curr_str)
		{
			free(limiter);
			return (false);
		}
		if (ft_strncmp(limiter, curr_str, ft_strlen(limiter)) == 0)
			break ;
		if (ft_printf("pipe heredoc> ") != -1
			&& write(fd, curr_str, ft_strlen(curr_str)) == -1)
		{
			free(curr_str);
			free(limiter);
			return (false);
		}
		free(curr_str);
	}
	free(curr_str);
	free(limiter);
	return (true);
}
