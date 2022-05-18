/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:32:18 by bgohan            #+#    #+#             */
/*   Updated: 2021/11/03 18:02:37 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	calc_len(int n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		++len;
	while (n != 0)
	{
		n /= 10;
		++len;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*s;
	size_t	len;
	size_t	i;
	int		sign;

	len = calc_len(n);
	s = malloc((len + 1) * sizeof(*s));
	if (!s)
		return (NULL);
	s[len] = 0;
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		s[0] = '-';
	}
	i = 0;
	while (i + (sign == -1) < len)
	{
		s[len - 1 - i] = sign * (n % 10) + '0';
		n /= 10;
		++i;
	}
	return (s);
}
