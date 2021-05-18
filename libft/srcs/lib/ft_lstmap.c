/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:09:47 by gvenet            #+#    #+#             */
/*   Updated: 2021/02/09 11:09:54 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *elem_f;
	t_list *lst_f;

	elem_f = NULL;
	lst_f = NULL;
	while (lst && f)
	{
		if (!(elem_f = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&elem_f, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_f, elem_f);
		lst = lst->next;
	}
	return (lst_f);
}
