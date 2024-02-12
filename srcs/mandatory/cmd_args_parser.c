/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_args_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:40:26 by dshatilo          #+#    #+#             */
/*   Updated: 2024/02/08 15:17:12 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		check_special_cmd(char ***command);
size_t	ft_2d_array_len(const char **str);
int		try_bash(char ***command);

int	cmd_args_parser(char ***command)
{
	int		status;
	int		mode;

	status = 0;
	mode = check_special_cmd(command);
	if (mode == 1)
		status = try_bash(command);
	else if (mode == 2)
		status = 0;
	return (status);
	(void)command;
	return (0);
}

int	check_special_cmd(char ***command)
{
	int		c_len;
	char	*c;

	c = **command;
	c_len = ft_strlen(c);
	if (ft_strncmp(c + c_len - 3, ".sh", 4) == 0)
		return (1);
	return (0);
}
//check which permissions are needed to use commands

int	try_bash(char ***command)
{
	char	**new_command;
	int		command_len;
	int		i;

	command_len = ft_2d_array_len((const char **)*command);
	new_command = (char **)ft_calloc(command_len + 2, sizeof(char *));
	if (!new_command)
		return (MALLOC_FAILURE);
	new_command[0] = ft_strdup("/bin/bash");
	if (new_command[0] == NULL)
	{
		free(new_command);
		return (MALLOC_FAILURE);
	}
	i = 0;
	while (i < command_len)
	{
		new_command[i + 1] = (*command)[i];
		i++;
	}
	free(*command);
	*command = new_command;
	return (0);
}

size_t	ft_2d_array_len(const char **str)
{
	size_t	length;

	length = 0;
	while (*(str + length) != 0)
		length++;
	return (length);
}
