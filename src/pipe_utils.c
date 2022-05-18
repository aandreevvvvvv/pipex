/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 04:13:41 by bgohan            #+#    #+#             */
/*   Updated: 2022/02/10 11:45:24 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void	create_pipes(t_args *args)
{
	size_t	i;

	args->pipes = malloc(sizeof(int *) * (args->n - 1));
	if (!args->pipes)
		exit(1);
	i = 0;
	while (i < args->n - 1)
	{
		args->pipes[i] = malloc(sizeof(int) * 2);
		if (!args->pipes[i])
			exit(1);
		if (pipe(args->pipes[i]) == -1)
			write_error(args->name, strerror(errno), NULL, 1);
		++i;
	}
}

void	close_pipes(t_args *args)
{
	size_t	i;

	i = 0;
	while (i < args->n - 1)
	{
		if (close(args->pipes[i][0]) == -1)
			write_error(args->name, strerror(errno), NULL, 1);
		if (close(args->pipes[i][1]) == -1)
			write_error(args->name, strerror(errno), NULL, 1);
		free(args->pipes[i]);
		++i;
	}
	free(args->pipes);
}

void	close_redundant_pipes(t_args *args, size_t i)
{
	size_t	j;

	j = 0;
	while (j < args->n - 1)
	{
		if (j != i)
			if (close(args->pipes[j][1]) == -1)
				write_error(args->name, strerror(errno), NULL, 1);
		if (j + 1 != i)
			if (close(args->pipes[j][0]) == -1)
				write_error(args->name, strerror(errno), NULL, 1);
		++j;
	}
}
