/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_px_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:04:45 by dshatilo          #+#    #+#             */
/*   Updated: 2024/02/03 13:54:20 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
