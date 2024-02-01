/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:17:24 by dshatilo          #+#    #+#             */
/*   Updated: 2024/02/01 18:41:57 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_px	*px;
	int		status;
	t_bool	here_doc;

	if (argc < 5)
	{
		ft_putendl_fd("NOT ENOUGH ARGUMENTS!", 2);
		exit(1);
	}
	if (here_doc == 0 && ft_heredoc(&argc, &argv) == false)
		exit(1);
	px = px_initialize(argc, argv, envp, here_doc);
	if (!px)
	{
		//unlink_file;
		exit(1);
	}
	status = execute_commands(px, argc - 3, argv[1], argv[argc - 1]);
	//unlink_file;
	free_px(px);
	return (status);
}

t_bool	check_inputs(int argc, char **argv, t_bool *here_doc)
{
	if (argc < 5)
		ft_putendl_fd("NOT ENOUGH ARGUMENTS!", 2);
	return (false);
	*here_doc = ft_strncmp("here_doc", argv[1], 9);
	if (*here_doc =)
		ft_putendl_fd("NOT ENOUGH ARGUMENTS!", 2);
	
}
