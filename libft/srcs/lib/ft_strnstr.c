/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:22:06 by gvenet            #+#    #+#             */
/*   Updated: 2021/02/09 11:11:08 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char			*ft_strnstr(const char *s, const char *c, size_t len)
{
	size_t		i;
	size_t		j;

	if (c[0] == '\0')
		return ((char *)s);
	j = 0;
	while (j < len && s[j])
	{
		i = 0;
		while (c[i] && s[j] && c[i] == s[j])
		{
			++i;
			++j;
		}
		if (j > len)
			break ;
		if (c[i] == '\0')
			return ((char *)&s[j - i]);
		j = j - i + 1;
	}
	return (0);
}
