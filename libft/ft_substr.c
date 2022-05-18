/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:02:27 by bgohan            #+#    #+#             */
/*   Updated: 2022/01/23 14:43:37 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_zero(void)
{
	char	*ans;

	ans = malloc(sizeof(char));
	if (!ans)
		return (NULL);
	ans[0] = 0;
	return (ans);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*ans;
	size_t		size;
	size_t		i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
	{
		return (ft_zero());
	}
	size = ft_min(len, ft_strlen(s + start));
	ans = ft_calloc(size + 1, sizeof(char));
	if (!ans)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ans[i] = s[start + i];
		++i;
	}
	ans[i] = 0;
	return (ans);
}
