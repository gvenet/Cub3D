/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:22:06 by gvenet            #+#    #+#             */
/*   Updated: 2021/02/09 11:11:02 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*d;
	size_t			l;

	if (s == NULL)
		return (NULL);
	l = ft_strlen(s);
	if (!(d = (char*)malloc((l + 1) * sizeof(char))))
		return (NULL);
	i = -1;
	while (++i < l)
		d[i] = f(i, s[i]);
	d[i] = '\0';
	return (d);
}
