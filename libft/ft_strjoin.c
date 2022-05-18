/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:06:34 by bgohan            #+#    #+#             */
/*   Updated: 2021/11/26 01:41:02 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*ans;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	ans = malloc((size + 1) * sizeof(char));
	if (!ans)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ans[i] = s1[i];
		++i;
	}
	j = 0;
	while (s2[j])
	{
		ans[i + j] = s2[j];
		++j;
	}
	ans[i + j] = 0;
	return (ans);
}
