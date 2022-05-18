/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 03:19:28 by bgohan            #+#    #+#             */
/*   Updated: 2021/11/03 18:32:32 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int		res;
	size_t	i;

	res = 0;
	i = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			++res;
		if (i > 0 && s[i - 1] == c && s[i] != c)
			++res;
		++i;
	}
	return (res);
}

static int	ft_word_len(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		++i;
	return (i);
}

static char	**ft_free(char **arr)
{
	size_t	i;

	if (!arr)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		if (arr[i])
			free(arr[i]);
		++i;
	}
	free(arr);
	return (NULL);
}

static char	*ft_append_word(char const *s, size_t *i, char c)
{
	size_t	word_len;
	char	*res;

	word_len = ft_word_len(s + *i, c);
	res = malloc((word_len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s + *i, word_len + 1);
	*i += word_len;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	cur_word;

	if (!s)
		return (NULL);
	res = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	cur_word = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			++i;
			continue ;
		}
		res[cur_word] = ft_append_word(s, &i, c);
		if (!res[cur_word])
			return (ft_free(res));
		++cur_word;
	}
	res[cur_word] = 0;
	return (res);
}
