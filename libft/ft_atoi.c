/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:31:09 by bgohan            #+#    #+#             */
/*   Updated: 2021/11/12 21:23:31 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ')
		return (1);
	return (c >= 9 && c <= 13);
}

static int	ft_skip(const char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		++i;
	if (str[i] == '+')
		++i;
	else if (str[i] == '-')
	{
		*sign = -1;
		++i;
	}
	return (i);
}

static long long	ft_check_overflow(long long ans, int digit)
{
	if (ans > 922337203685477580 || (ans == 922337203685477580 && digit > 7))
		return (9223372036854775807);
	if (ans < -922337203685477580 || (ans == -922337203685477580 && digit > 8))
		return (-9223372036854775807 - 1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long long	ans;
	int			i;
	int			sign;

	ans = 0;
	sign = 1;
	i = ft_skip(str, &sign);
	while (str[i] && ft_isdigit(str[i]))
	{
		if (ft_check_overflow(ans, sign * (str[i] - '0')))
			return ((int)ft_check_overflow(ans, sign * (str[i] - '0')));
		ans = ans * 10 + sign * (str[i] - '0');
		if (ans > 0 && sign < 0)
			ans *= -1;
		++i;
	}
	return ((int)ans);
}
