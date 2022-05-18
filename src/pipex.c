/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:26:20 by bgohan            #+#    #+#             */
/*   Updated: 2022/02/10 19:41:40 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv, char **envp)
{
	t_args	*args;
	pid_t	*pids;

	if (argc < 5)
		exit(0);
	args = parse(argc, argv, envp);
	create_pipes(args);
	pids = start_processes(args);
	close_pipes(args);
	close_files(args);
	wait_processes(pids, args->n);
	free_args(args);
	return (0);
}
