/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:15:54 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/08 17:25:06 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_abs(long value)
{
	if (value < 0)
		value *= -1;
	return (value);
}