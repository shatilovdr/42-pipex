/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:17:24 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/27 20:34:54 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**cmd1(void)
{
	char	**cmd1;

	cmd1 = (char **)ft_calloc(3, sizeof(char *));
	cmd1[0] = ft_strdup("/bin/cat");
	return (cmd1);
}

char	**cmd2(void)
{
	char	**cmd2;

	cmd2 = (char **)ft_calloc(3, sizeof(char *));
	cmd2[0] = ft_strdup("/bin/ls");
	cmd2[1] = ft_strdup("-la");
	return (cmd2);
}

int	main(int argc, char **argv, char **envp)
{
	t_px	*px;
	int		status;
	char	***cmds;

	cmds = (char ***)malloc(sizeof(char **) * 2);
	cmds[0] = cmd2();
	cmds[1] = cmd1();
	if (argc != 5)
	{
		ft_putendl_fd("NOT ENOUGH ARGUMENTS!", 2);
		// exit(1);
		argc = 5;
	}
	px = px_initialize(argc, argv, envp);
	// parse_args(px, argc - 3, argv + 2);
	px->cmds = cmds;
	status = execute_commands(px, argc - 3);
	wait(NULL);
	wait(NULL);
	// free_px(px);
	return (status);
}
