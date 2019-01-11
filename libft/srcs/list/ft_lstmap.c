/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:24:18 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/04 18:26:36 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ptr_old;
	t_list	*head;
	t_list	*ptr;

	ptr_old = lst;
	head = f(ptr_old);
	ptr = head;
	ptr_old = ptr_old->next;
	while (ptr_old->next != NULL)
	{
		ptr->next = f(ptr_old);
		ptr = ptr->next;
		ptr_old = ptr_old->next;
	}
	ptr->next = f(ptr_old);
	ptr->next->next = NULL;
	return (head);
}
