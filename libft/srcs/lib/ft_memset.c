/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:22:06 by gvenet            #+#    #+#             */
/*   Updated: 2021/02/09 11:10:17 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char		*m;
	size_t		i;

	m = (char*)s;
	i = 0;
	while (i < n)
	{
		m[i] = (char)c;
		i++;
	}
	return (s);
}
