/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:51:21 by bgohan            #+#    #+#             */
/*   Updated: 2022/01/26 20:49:25 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	pos;
	size_t	i;

	pos = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[pos])
	{
		i = 0;
		while (haystack[pos + i] && needle[i] && pos + i < len)
		{
			if (haystack[pos + i] != needle[i])
				break ;
			++i;
		}
		if (!needle[i])
			return ((char *)haystack + pos);
		++pos;
	}
	return (NULL);
}
