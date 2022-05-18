/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:23:49 by bgohan            #+#    #+#             */
/*   Updated: 2022/01/08 20:59:18 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
	Add thread in list
	Return 1 for error
	Return 0 for success
*/
int	list_push(int fd, t_list **lst)
{
	t_list			*cur;

	cur = malloc(sizeof(t_list));
	if (!cur)
		return (1);
	cur->fd = fd;
	cur->next = NULL;
	cur->buf = malloc(BUFFER_SIZE * sizeof(char));
	if (!cur->buf)
	{
		free(cur);
		return (1);
	}
	cur->pos = 0;
	cur->read_res = 0;
	if (!*lst)
		*lst = cur;
	else
	{
		cur->next = *lst;
		*lst = cur;
	}
	return (0);
}

/*
	Find thread for fd. If does not exist - create it
	Return thread
*/
t_list	*find_thread(int fd, t_list **lst)
{
	t_list			*cur;

	cur = *lst;
	while (cur)
	{
		if (cur->fd == fd)
			return (cur);
		cur = cur->next;
	}
	if (list_push(fd, lst))
		return (free_list(*lst));
	return (*lst);
}

/* 	
	Read from fd in buffer
	Return 1 for error
	Returns 0 for success
*/
int	read_fd(t_list *thread)
{
	if (thread->pos < thread->read_res)
		return (0);
	thread->pos = 0;
	thread->read_res = read(thread->fd, thread->buf, BUFFER_SIZE);
	if (thread->read_res == -1)
		return (1);
	if (thread->read_res == BUFFER_SIZE)
		return (0);
	thread->buf[thread->read_res] = 0;
	return (0);
}

void	*free_list(t_list *lst)
{
	t_list			*cur;

	if (!lst)
		return (NULL);
	cur = lst;
	while (cur)
	{
		if (cur->buf)
			free(cur->buf);
		cur = cur->next;
		free(lst);
		lst = cur;
	}
	return (NULL);
}

void	free_fd(t_list **lst, int fd)
{
	t_list	*prev;
	t_list	*cur;

	prev = NULL;
	cur = *lst;
	while (cur && cur->fd != fd)
	{
		prev = cur;
		cur = cur -> next;
	}
	if (!cur)
		return ;
	if (prev)
		prev -> next = cur -> next;
	else
		*lst = cur -> next;
	if (cur->buf)
		free (cur->buf);
	free(cur);
}
