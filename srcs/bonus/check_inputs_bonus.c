/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:03:37 by dshatilo          #+#    #+#             */
/*   Updated: 2024/02/13 10:22:47 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	remove_escape_characters(int argc, char **argv);

t_bool	check_inputs(int argc, char **argv, t_bool *here_doc)
{
	if (argc < 5)
	{
		ft_putendl_fd("NOT ENOUGH ARGUMENTS!\n"
			"example: file1 cmd1 cmd2 file2", 2);
		return (false);
	}
	*here_doc = (ft_strncmp("here_doc", argv[1], 9) == 0);
	if (*here_doc == true && argc < 6)
	{
		ft_putendl_fd("NOT ENOUGH ARGUMENTS FOR HERE_DOC!\n"
			"example: here_doc LIMITER cmd1 cmd2 file", 2);
		return (false);
	}
	remove_escape_characters(argc, argv);
	return (true);
}

void	remove_escape_characters(int argc, char **argv)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j])
		{
			if (argv[i][j] == '\\')
			{
				k = j;
				while (argv[i][k] != '\0')
				{
					argv[i][k] = argv[i][k + 1];
					k++;
				}
			}
			j++;
		}
		i++;
	}
}
