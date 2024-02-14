/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 09:56:32 by dshatilo          #+#    #+#             */
/*   Updated: 2024/02/14 11:04:57 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_BONUS_H
# define ERRORS_BONUS_H

/*
* Error codes for user/programm failures such as:
* 	-incorrect number of arguments
* 	-unlink errors
* 	-write errors
* 	-malloc errors
* 	-open errors
* 	-close errors
*/
# ifndef ARGS_FAILURE
#  define ARGS_FAILURE 1
# endif

# ifndef HERE_DOC_FAILURE
#  define HERE_DOC_FAILURE -2
# endif

# ifndef MALLOC_FAILURE
#  define MALLOC_FAILURE -3
# endif

# ifndef UNLINK_FAILURE
#  define UNLINK_FAILURE -4
# endif

# ifndef OPEN_FAILURE
#  define OPEN_FAILURE -5
# endif

# ifndef CLOSE_FAILURE
#  define CLOSE_FAILURE -6
# endif

# ifndef PIPE_FAILURE
#  define PIPE_FAILURE -7
# endif

# ifndef FORK_FAILURE
#  define FORK_FAILURE -8
# endif

/*
* Error codes for pipex failures such as:
* 	-failures with permission to files/commands open/executions
* 	-failures when files/commands don't exist
*/

# ifndef FD_FAILURE
#  define FD_FAILURE 1
# endif

# ifndef CMD_PD_FAILURE
#  define CMD_PD_FAILURE 126
# endif

# ifndef CMD_NF_FAILURE
#  define CMD_NF_FAILURE 127
# endif

# ifndef EXECVE_FAILURE
#  define EXECVE_FAILURE 127
# endif

#endif