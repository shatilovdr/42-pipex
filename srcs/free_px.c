/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_px.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:04:45 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/24 12:07:28 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_px(t_px *px)
{
	ft_free_2d_array(px->paths);
	ft_free_2d_array(px->pipes);
	ft_free_2d_array(px->cmds);
	free(px->pids);
	free(px);
}
