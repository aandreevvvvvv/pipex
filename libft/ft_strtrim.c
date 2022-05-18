/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:07:41 by bgohan            #+#    #+#             */
/*   Updated: 2021/11/03 18:31:37 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_beginning(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (!ft_strchr(set, s1[i]))
			return (i);
		++i;
	}
	return (i);
}

static char	*empty_str(void)
{
	char	*ans;

	ans = malloc(sizeof(char));
	if (!ans)
		return (NULL);
	ans[0] = 0;
	return (ans);
}

static size_t	ft_count_ending(char const *s1, char const *set)
{
	size_t	i;
	size_t	cur;

	i = 0;
	cur = 0;
	while (s1[i])
	{
		if (ft_strchr(set, s1[i]))
			++cur;
		else
			cur = 0;
		++i;
	}
	return (cur);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	beg;
	char	*ans;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	beg = ft_count_beginning(s1, set);
	if (ft_strlen(s1) == beg)
	{
		return (empty_str());
	}
	len = ft_strlen(s1) - beg - ft_count_ending(s1, set);
	ans = malloc((len + 1) * sizeof(char));
	if (!ans)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ans[i] = s1[beg + i];
		++i;
	}
	ans[i] = 0;
	return (ans);
}
