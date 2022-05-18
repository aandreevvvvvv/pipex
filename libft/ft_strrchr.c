/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:33:35 by bgohan            #+#    #+#             */
/*   Updated: 2022/01/26 20:55:51 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ans;
	char	*cur;

	ans = NULL;
	cur = (char *)s;
	while (*cur)
	{
		if (*cur == (char)c)
			ans = cur;
		++cur;
	}
	if (c == 0)
		ans = cur;
	return (ans);
}
