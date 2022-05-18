/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:32:51 by bgohan            #+#    #+#             */
/*   Updated: 2021/11/02 19:32:51 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*cur;

	cur = (char *)s;
	while (*cur && *cur != (char)c)
		++cur;
	if (*cur == (char)c)
		return (cur);
	return (NULL);
}
