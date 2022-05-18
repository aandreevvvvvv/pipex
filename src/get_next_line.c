/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 04:17:52 by bgohan            #+#    #+#             */
/*   Updated: 2022/01/10 03:51:03 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		++i;
	return (i);
}

size_t	linelen(t_list *thread)
{
	size_t	i;

	i = 0;
	while (thread->pos + i < (uint)BUFFER_SIZE)
	{
		if (thread->buf[thread->pos + i] == 0)
			break ;
		if (thread->buf[thread->pos + i] == '\n')
		{
			++i;
			break ;
		}
		++i;
	}
	return (i);
}

char	*append(char *str, char *buf, size_t len)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	newstr = malloc((ft_strlen(str) + len + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	i = 0;
	while (str && str[i])
	{
		newstr[i] = str[i];
		++i;
	}
	j = 0;
	while (j < len)
	{
		newstr[i + j] = buf[j];
		++j;
	}
	newstr[i + j] = 0;
	return (newstr);
}

/*
	Return -1 for error
	Return 0 if end of line reached
	Return 1 if end of line was not reached
*/
int	process_buf(t_list *thread, char **line)
{
	char	*newline;
	size_t	len;

	if (thread->read_res == 0)
		return (0);
	len = linelen(thread);
	newline = append(*line, thread->buf + thread->pos, len);
	free (*line);
	if (!newline)
		return (-1);
	*line = newline;
	thread->pos += len;
	if (!thread->buf[thread->pos - 1] || thread->buf[thread->pos - 1] == '\n')
		return (0);
	read_fd(thread);
	return (thread->read_res);
}

char	*get_next_line(int fd)
{
	char			*line;
	t_list			*thread;
	static t_list	*lst;
	int				ret;

	if (read(fd, NULL, 0) || BUFFER_SIZE < 0)
		return (NULL);
	thread = find_thread(fd, &lst);
	if (!thread || read_fd(thread))
		return (free_list(lst));
	line = NULL;
	ret = 1;
	while (ret != 0)
	{
		ret = process_buf(thread, &line);
		if (ret == -1)
			return (free_list(lst));
		if (thread->read_res == 0)
			free_fd(&lst, fd);
	}
	return (line);
}
