/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:17:24 by dshatilo          #+#    #+#             */
/*   Updated: 2024/02/02 00:11:50 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_px	*px;
	int		status;
	t_bool	here_doc;

	if (check_inputs(argc, argv, &here_doc) == false)
		return (EXIT_FAILURE);
	if (here_doc == true && ft_heredoc(&argc, &argv) == false)
	{
		ft_putendl_fd("Can't execute here_doc part", 2);
		return (EXIT_FAILURE);
	}
	int i = 0;
	while (i < argc)
	{
		ft_printf("%s\n", argv[i]);
		i++;
	}
	exit(0);
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
