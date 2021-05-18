/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:03:27 by gvenet            #+#    #+#             */
/*   Updated: 2021/02/09 11:09:59 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int		ft_lstsize(t_list *lst)
{
	int		i_count;

	i_count = 1;
	if (lst)
	{
		while (lst->next != NULL)
		{
			i_count++;
			lst = lst->next;
		}
		return (i_count);
	}
	return (0);
}
