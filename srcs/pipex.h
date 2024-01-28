/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:16:11 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/28 20:45:31 by dshatilo         ###   ########.fr       */
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
	char	*in_flie;
	char	*out_file;
	char	**paths;
	int		pipes[2][2];
	char	***cmds;
	char	**envp;
	pid_t	*pids;
	int		status;
}	t_px;

t_px	*px_initialize(int argc, char **argv, char **envp);
int		execute_commands(t_px *px, int num);
int		open_input_file(char *location);
int		open_output_file(char *location);
int		check_access(char *location, int mode);



#endif
