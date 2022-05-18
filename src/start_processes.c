/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_processes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 06:10:00 by bgohan            #+#    #+#             */
/*   Updated: 2022/02/10 19:29:51 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

static void	here_doc_process(t_args *args)
{
	char	*line;

	close_redundant_pipes(args, 0);
	write(STDOUT_FILENO, "pipe heredoc> ", ft_strlen("pipe heredoc> "));
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (ft_strncmp(line, args->limiter, ft_strlen(args->limiter)))
			write(args->pipes[0][1], line, ft_strlen(line));
		else
			break ;
		free(line);
		write(STDOUT_FILENO, "pipe heredoc> ", ft_strlen("pipe heredoc> "));
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	exit(1);
}

static void	first_process(t_args *args)
{
	close_redundant_pipes(args, 0);
	if (args->in_fd < 0)
		exit(1);
	if (dup2(args->in_fd, STDIN_FILENO) == -1)
		write_error(args->name, strerror(errno), NULL, 1);
	if (dup2(args->pipes[0][1], STDOUT_FILENO) == -1)
		write_error(args->name, strerror(errno), NULL, 1);
	if (!args->cmdpath[0])
		write_error(args->name, "command not found", args->argv[0][0], 1);
	execve(args->cmdpath[0], args->argv[0], args->envp);
	write_error(args->name, strerror(errno), NULL, 1);
}

static void	last_process(t_args *args)
{
	close_redundant_pipes(args, args->n - 1);
	if (args->out_fd < 0)
		exit(1);
	if (dup2(args->pipes[args->n - 2][0], STDIN_FILENO) == -1)
		write_error(args->name, strerror(errno), NULL, 1);
	if (dup2(args->out_fd, STDOUT_FILENO) == -1)
		write_error(args->name, strerror(errno), NULL, 1);
	if (!args->cmdpath[args->n - 1])
		write_error(args->name, "command not found", \
											args->argv[args->n - 1][0], 1);
	execve(args->cmdpath[args->n - 1], args->argv[args->n - 1], args->envp);
	write_error(args->name, strerror(errno), NULL, 1);
}

static void	interm_process(t_args *args, size_t i)
{
	close_redundant_pipes(args, i);
	if (dup2(args->pipes[i - 1][0], STDIN_FILENO) == -1)
		write_error(args->name, strerror(errno), NULL, 1);
	if (dup2(args->pipes[i][1], STDOUT_FILENO) == -1)
		write_error(args->name, strerror(errno), NULL, 1);
	if (!args->cmdpath[i])
		write_error(args->name, "command not found", args->argv[i][0], 1);
	execve(args->cmdpath[i], args->argv[i], args->envp);
	write_error(args->name, strerror(errno), NULL, 1);
}

pid_t	*start_processes(t_args *args)
{
	size_t	i;
	pid_t	*pids;

	pids = malloc(args->n * sizeof(pid_t));
	if (!pids)
		exit (1);
	i = 0;
	while (i < args->n)
	{
		pids[i] = fork();
		if (pids[i] < 0)
			write_error(args->name, strerror(errno), NULL, 1);
		else if (pids[i] == 0)
		{
			if (i == 0 && args->limiter)
				here_doc_process(args);
			else if (i == 0)
				first_process(args);
			else if (i == args->n - 1)
				last_process(args);
			interm_process(args, i);
		}
		++i;
	}
	return (pids);
}
