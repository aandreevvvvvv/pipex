/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 04:17:55 by bgohan            #+#    #+#             */
/*   Updated: 2021/11/18 20:59:29 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096 
# endif

# include <stddef.h>
# include <sys/types.h>

typedef struct s_list
{
	int				fd;
	char			*buf;
	int				pos;
	ssize_t			read_res;
	struct s_list	*next;
}	t_list;

char		*get_next_line(int fd);
t_list		*find_thread(int fd, t_list **lst);
int			list_push(int fd, t_list **lst);
int			read_fd(t_list *lst);
void		*free_list(t_list *lst);
size_t		ft_strlen(char *s);
size_t		linelen(t_list *lst);
char		*append(char *str, char *buf, size_t len);
int			process_buf(t_list *thread, char **line);
void		free_fd(t_list **lst, int fd);

#endif