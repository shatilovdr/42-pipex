/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:03:37 by dshatilo          #+#    #+#             */
/*   Updated: 2024/02/13 09:38:51 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	remove_escape_characters(int argc, char **argv);

t_bool	check_inputs(int argc, char **argv)
{
	if (argc != 5)
	{
		ft_putendl_fd("INCORRECT NUMBER OF ARGUMENTS!\n"
			"example: file1 cmd1 cmd2 file2", 2);
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
