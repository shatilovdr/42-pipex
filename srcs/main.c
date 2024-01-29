/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:17:24 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/29 18:43:58 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**cmd1(void)
{
	char	**cmd1;

	cmd1 = (char **)ft_calloc(3, sizeof(char *));
	cmd1[0] = ft_strdup("/bin/casdft");
	return (cmd1);
}

char	**cmd2(void)
{
	char	**cmd2;

	// cmd2 = (char **)ft_calloc(3, sizeof(char *));
	// cmd2[0] = ft_strdup("/bin/ls");
	// cmd2[1] = ft_strdup("-la");
	cmd2 = (char **)ft_calloc(3, sizeof(char *));
	cmd2[0] = ft_strdup("/bin/cat");
	return (cmd2);
}

char	**cmd3(void)
{
	char	**cmd3;

	cmd3 = (char **)ft_calloc(3, sizeof(char *));
	cmd3[0] = ft_strdup("/usr/bin/wc");
	cmd3[1] = ft_strdup("-l");
	return (cmd3);
}

int	main(int argc, char **argv, char **envp)
{
	t_px	*px;
	int		status;
	char	***cmds;

	cmds = (char ***)malloc(sizeof(char **) * 3);
	cmds[0] = cmd2();
	cmds[1] = cmd1();
	cmds[2] = cmd3();
	if (argc < 5)
	{
		ft_putendl_fd("NOT ENOUGH ARGUMENTS!", 2);
		exit(1);
	}
	px = px_initialize(argc, envp);
	// parse_args(px, argc - 3, argv + 2);
	px->cmds = cmds;
	status = execute_commands(px, argc - 3, argv[1], argv[argc - 1]);
	// free_px(px);
	return (status);
}
