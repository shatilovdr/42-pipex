/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 09:56:32 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/25 16:25:01 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# ifndef OPEN_FAILURE
#  define OPEN_FAILURE -2
# endif

# ifndef PIPE_FAILURE
#  define PIPE_FAILURE -3
# endif

# ifndef FORK_FAILURE
#  define FORK_FAILURE -4
# endif

# ifndef CLOSE_FAILURE
#  define CLOSE_FAILURE -5
# endif

#endif