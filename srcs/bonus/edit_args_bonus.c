/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_args_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:44:04 by dshatilo          #+#    #+#             */
/*   Updated: 2024/02/03 14:10:37 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	edit_args(int *argc, char ***argv)
{
	int	i;
	int	arg_num;

	arg_num = *argc;
	i = 3;
	while (i < arg_num)
	{
		(*argv)[i - 1] = (*argv)[i];
		i++;
	}
	(*argv)[1] = ".here_doc";
	*argc = arg_num - 1;
}
