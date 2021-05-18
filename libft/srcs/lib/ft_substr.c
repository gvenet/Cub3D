/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:25:15 by gvenet            #+#    #+#             */
/*   Updated: 2021/02/09 11:11:17 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*d;
	size_t	i;
	size_t	s_len;

	i = -1;
	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (len > s_len)
		len = s_len;
	if (!(d = (char*)ft_calloc((len + 1), sizeof(char))))
		return (NULL);
	if (start >= s_len)
	{
		d[0] = 0;
		return (d);
	}
	while (++i < len)
		d[i] = s[start++];
	return (d);
}
