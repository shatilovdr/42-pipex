/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 09:56:32 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/29 19:01:27 by dshatilo         ###   ########.fr       */
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

# ifndef FD_FAILURE
#  define FD_FAILURE -6
# endif

# ifndef EXECVE_FAILURE
#  define EXECVE_FAILURE -7
# endif

#endif