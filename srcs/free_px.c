/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_px.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:04:45 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/30 12:26:00 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_px(t_px *px)
{
	if (px->paths)
		ft_free_2d_array(px->paths);
	if (px->cmds)
		ft_free_2d_array(px->cmds);
	if (px->pids)
		free(px->pids);
	free(px);
}
