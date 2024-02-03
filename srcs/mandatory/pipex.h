/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:16:11 by dshatilo          #+#    #+#             */
/*   Updated: 2024/02/03 13:46:20 by dshatilo         ###   ########.fr       */
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

# ifndef NSFD
#  define NSFD -100
# endif

# ifndef PD
#  define PD -200
# endif

# include <string.h>
# include <sys/wait.h>
# include "../../lib/libft/libft.h"
# include "errors.h"

typedef struct s_px
{
	char	**cmds;
	char	**paths;
	pid_t	*pids;
	char	**envp;
}	t_px;

t_bool	check_inputs(int argc);
t_px	*px_initialize(int argc, char **argv, char **envp);
int		execute_commands(t_px *px, int num, char *infile, char *outfile);
int		open_input_file(char *location);
int		open_output_file(char *location);
int		check_access(char *location, int mode);
int		get_command(t_px *px, int i, char ***command);
int		find_executable(char **command, char **paths);
int		cmd_args_parser(char ***cmd);
int		wait_childs(t_px *px, int num);
void	free_px(t_px *px);
int		fork_failure(int fd_read_prev, int fd_read, int fd_write);
int		pipe_failure(int fd_read_prev);
void	chld_fd_cls_fail(t_px *px, int in, int out, char **cmd);

#endif