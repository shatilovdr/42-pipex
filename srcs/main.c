/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:17:24 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/30 18:53:14 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_px	*px;
	int		status;

	if (argc < 5)
	{
		ft_putendl_fd("NOT ENOUGH ARGUMENTS!", 2);
		exit(1);
	}
	//if (heredoc() == false)
		//exit(1);
	px = px_initialize(argc, argv, envp);
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
