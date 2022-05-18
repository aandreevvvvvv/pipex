/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:32:42 by bgohan            #+#    #+#             */
/*   Updated: 2021/11/03 04:14:40 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		digit;

	digit = n % 10;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n /= -10;
		digit *= -1;
	}
	else
		n /= 10;
	if (n)
		ft_putnbr_fd(n, fd);
	ft_putchar_fd(digit + '0', fd);
}
