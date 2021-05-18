/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:22:06 by gvenet            #+#    #+#             */
/*   Updated: 2021/02/09 11:10:08 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *m1;
	const unsigned char *m2;

	m1 = (const unsigned char*)s1;
	m2 = (const unsigned char*)s2;
	while (n)
	{
		if (*m1 != *m2)
			return (*m1 - *m2);
		m1++;
		m2++;
		n--;
	}
	return (0);
}
