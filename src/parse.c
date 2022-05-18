/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:41:14 by bgohan            #+#    #+#             */
/*   Updated: 2022/02/10 19:40:23 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

static void	parse_files(int argc, char **argv, t_args *args)
{
	if (ft_strncmp(argv[0], "here_doc", ft_strlen("here_doc")) == 0)
	{
		if (argc < 5)
			exit(0);
		args->limiter = argv[1];
		args->in_fd = 0;
		args->out_fd = open(argv[argc - 1], \
								O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	else
	{
		args->limiter = NULL;
		args->in_fd = open(argv[0], O_RDONLY);
		if (args->in_fd < 0)
			write_error(args->name, strerror(errno), argv[0], 0);
		args->out_fd = open(argv[argc - 1], \
								O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	args->n = argc - 2;
	if (args->out_fd < 0)
		write_error(args->name, strerror(errno), argv[argc - 1], 0);
}

static void	parse_argvs(char **argv, t_args *args)
{
	size_t	i;

	args->argv = malloc(sizeof(char **) * args->n);
	if (!args->argv)
		exit(1);
	i = 0;
	while (i < args->n)
	{
		args->argv[i] = ft_split(argv[i], ' ');
		if (!args->argv[i])
			exit(1);
		++i;
	}
}

static void	parse_cmdpath(t_args *args)
{
	size_t	i;
	char	**path;

	path = parse_path(args->envp);
	args->cmdpath = malloc(sizeof(char *) * args->n);
	if (!args->cmdpath)
		exit(1);
	i = 0;
	while (i < args->n)
	{
		args->cmdpath[i] = find_cmdpath(path, args->argv[i][0]);
		++i;
	}
	i = 0;
	if (path)
	{
		while (path[i])
			free(path[i++]);
		free(path);
	}
}

t_args	*parse(int argc, char **argv, char **envp)
{
	t_args	*args;

	args = malloc(sizeof(*args));
	if (!args)
		exit(1);
	args->name = argv[0];
	parse_files(argc - 1, argv + 1, args);
	args->envp = envp;
	parse_argvs(argv + 2, args);
	parse_cmdpath(args);
	return (args);
}
