/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:06:14 by bgohan            #+#    #+#             */
/*   Updated: 2021/11/02 19:33:09 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(dst);
	if (len >= dstsize)
		return (ft_strlen(src) + dstsize);
	while (len + i + 1 < dstsize && src[i])
	{
		dst[len + i] = src[i];
		++i;
	}
	dst[len + i] = 0;
	return (len + ft_strlen(src));
}
