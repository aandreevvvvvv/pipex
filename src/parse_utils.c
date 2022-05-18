/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:09:39 by bgohan            #+#    #+#             */
/*   Updated: 2022/02/10 13:23:08 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

char	**parse_path(char **envp)
{
	size_t	i;
	char	**path;
	char	*full_path;

	i = 0;
	full_path = NULL;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", 4))
		{
			full_path = envp[i];
			break ;
		}
		++i;
	}
	if (!full_path)
		return (NULL);
	path = ft_split(full_path + 5, ':');
	if (!path)
		exit(1);
	return (path);
}

char	*find_cmdpath(char **path, char *cmdname)
{
	size_t	i;
	char	*cmdpath;

	if (access(cmdname, X_OK) == 0)
		return (ft_strdup(cmdname));
	cmdname = ft_strjoin("/", cmdname);
	if (!cmdname)
		exit(1);
	i = 0;
	while (path && path[i])
	{
		cmdpath = ft_strjoin(path[i], cmdname);
		if (!cmdpath)
			exit (1);
		if (access(cmdpath, X_OK) == 0)
		{
			free(cmdname);
			return (cmdpath);
		}
		free(cmdpath);
		++i;
	}
	free(cmdname);
	return (NULL);
}
