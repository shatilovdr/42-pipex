/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:16:11 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/28 22:47:56 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# ifndef READ
#  define READ 0
# endif
# ifndef WRITE
#  define WRITE 1
# endif
# ifndef CHILD
#  define CHILD 0
# endif

# include <string.h>
# include <sys/wait.h>
#include <stdio.h>
# include "../lib/libft/libft.h"
# include "errors.h"

typedef struct s_px
{
	char	**paths;
	char	***cmds;
	char	**envp;
	pid_t	*pids;

}	t_px;

t_px	*px_initialize(int argc, char **envp);
int		execute_commands(t_px *px, int num, char *infile, char *outfile);
int		open_input_file(char *location);
int		open_output_file(char *location);
int		check_access(char *location, int mode);

int		fork_failure(int fd_read_prev, int fd_read, int fd_write);
void	chld_close_failure(int fd_read_prev, int fd_write);
int		pipe_failure(int fd_read_prev);

#endif
