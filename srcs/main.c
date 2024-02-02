/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:17:24 by dshatilo          #+#    #+#             */
/*   Updated: 2024/02/02 17:11:30 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_px	*px;
	int		status;
	t_bool	here_doc;

	if (check_inputs(argc, argv, &here_doc) == false)
		return (ARGS_FAILURE);
	if (here_doc == true && ft_heredoc(&argv) == false)
	{
		ft_putendl_fd("Can't execute here_doc part", 2);
		return (HERE_DOC_FAILURE);
	}
	if (here_doc == true)
		edit_args(&argc, &argv);
	px = px_initialize(argc, argv, envp, here_doc);
	if (!px)
	{
		unlink(".here_doc");
		return (MALLOC_FAILURE);
	}
	status = execute_commands(px, argc - 3, argv[1], argv[argc - 1]);
	if (here_doc == true && unlink(".here_doc") == -1)
		status = UNLINK_FAILURE;
	free_px(px);
	return (status);
}
