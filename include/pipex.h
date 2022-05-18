/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:26:47 by bgohan            #+#    #+#             */
/*   Updated: 2022/02/10 11:46:55 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stddef.h>
# include <sys/types.h>

typedef struct s_args
{
	char	*name;
	char	*limiter;
	int		in_fd;
	int		out_fd;
	char	***argv;
	char	**envp;
	char	**cmdpath;
	int		**pipes;
	size_t	n;
}	t_args;

t_args	*parse(int argc, char **argv, char **envp);
void	create_pipes(t_args *args);
pid_t	*start_processes(t_args *args);
void	close_pipes(t_args *args);

char	**parse_path(char **envp);
char	*find_cmdpath(char **path, char *cmdname);
void	close_redundant_pipes(t_args *args, size_t i);
char	*get_next_line(int fd);

void	close_files(t_args *args);
void	wait_processes(pid_t *pids, size_t n);
void	write_error(char *pref, char *error, char *suff, int do_exit);
void	free_args(t_args *args);

#endif