/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:24:18 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/21 16:21:25 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ptr;
	t_list	*tmp;

	ptr = lst;
	f(lst);
	while (ptr->next != NULL)
	{
		tmp = f(ptr);
		tmp = ft_lstnew(tmp->content, tmp->content_size);
		ptr = ptr->next;
		tmp->next = ptr;
	}
	tmp = f(ptr);
	tmp = ft_lstnew(tmp->content, tmp->content_size);
	tmp->next = NULL;
	return (tmp);
}
