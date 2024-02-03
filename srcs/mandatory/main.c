/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:17:24 by dshatilo          #+#    #+#             */
/*   Updated: 2024/02/03 12:58:42 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_px	*px;
	int		status;

	if (check_inputs(argc) == false)
		return (ARGS_FAILURE);
	px = px_initialize(argc, argv, envp);
	if (!px)
		return (MALLOC_FAILURE);
	status = execute_commands(px, argc - 3, argv[1], argv[argc - 1]);
	free_px(px);
	return (status);
}
