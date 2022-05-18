/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 04:44:21 by bgohan            #+#    #+#             */
/*   Updated: 2022/01/19 15:14:34 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstclear(t_list **lst)
{
	t_list	*cur;

	while (*lst)
	{
		cur = *lst;
		*lst = cur->next;
		free(cur);
	}
	return (NULL);
}
