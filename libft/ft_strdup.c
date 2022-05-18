/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:32:53 by bgohan            #+#    #+#             */
/*   Updated: 2021/11/02 19:32:54 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ans;
	size_t	i;

	len = ft_strlen(s1);
	ans = (char *)ft_calloc(len + 1, sizeof(char));
	if (!ans)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ans[i] = s1[i];
		++i;
	}
	return (ans);
}
