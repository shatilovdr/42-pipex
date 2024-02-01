/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 22:45:53 by dshatilo          #+#    #+#             */
/*   Updated: 2024/02/02 00:13:14 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_bool	read_stdin_write_to_file(int fd, char *limiter);
void	edit_args(int *argc, char ***argv);

t_bool	ft_heredoc(int *argc, char ***argv)
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
	if (read_stdin_write_to_file(fd, limiter) == false)
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
	edit_args(argc, argv);
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
		if (write(fd, curr_str, ft_strlen(curr_str)) == -1)
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

void	edit_args(int *argc, char ***argv)
{
	int	i;
	int	arg_num;

	arg_num = *argc;
	i = 3;
	while (i < arg_num)
	{
		(*argv)[i - 1] = (*argv)[i];
		i++;
	}
	(*argv)[1] = ".here_doc";
	*argc = arg_num - 1;
}
