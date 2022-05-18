/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgohan <bgohan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 04:48:51 by bgohan            #+#    #+#             */
/*   Updated: 2022/01/19 15:18:38 by bgohan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int))
{
	t_list	*res;
	t_list	*new;
	t_list	*cur;

	res = NULL;
	cur = lst;
	while (cur)
	{
		new = ft_lstnew(f(cur->content));
		if (!new)
		{
			ft_lstclear(&res);
			return (NULL);
		}
		ft_lstadd_back(&res, new);
		cur = cur->next;
	}
	return (res);
}
