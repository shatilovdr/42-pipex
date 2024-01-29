/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_childs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:20:23 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/29 12:25:09 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	wait_childs(t_px *px, int num)
{
	int	i;
	int	status;

	i = 0;
	while (i < num)
	{
		waitpid(px->pids[i], &status, 0);
		i++;
	}
	return (status);
}
