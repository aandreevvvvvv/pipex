/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:49:41 by bgohan            #+#    #+#             */
/*   Updated: 2022/02/10 19:29:44 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

void	write_error(char *pref, char *error, char *suff, int do_exit)
{
	write(2, pref, ft_strlen(pref));
	write(2, ": ", 2);
	write(2, error, ft_strlen(error));
	if (suff)
	{
		write(2, ": ", 2);
		write(2, suff, ft_strlen(suff));
	}
	write(2, "\n", 1);
	if (do_exit)
		exit(1);
}

void	close_files(t_args *args)
{
	if (args->in_fd > 0)
		if (close(args->in_fd) == -1)
			write_error(args->name, strerror(errno), NULL, 1);
	if (args->out_fd > 0)
		if (close(args->out_fd) == -1)
			write_error(args->name, strerror(errno), NULL, 1);
}

void	wait_processes(pid_t *pids, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		waitpid(pids[i++], NULL, 0);
	free(pids);
}

void	free_args(t_args *args)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < args->n)
	{
		j = 0;
		while (args->argv[i][j])
			free(args->argv[i][j++]);
		free(args->argv[i]);
		free(args->cmdpath[i]);
		++i;
	}
	free(args->argv);
	free(args->cmdpath);
	free(args);
}
