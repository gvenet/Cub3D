/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:22:06 by gvenet            #+#    #+#             */
/*   Updated: 2021/02/09 11:11:14 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int		ft_contain_set(char c, char *set)
{
	int i;
	int v;

	v = 0;
	i = -1;
	while (set[++i])
		if (set[i] == c)
			v++;
	return (v >= 1);
}

static char		*ft_return_blank(char *d)
{
	d = NULL;
	if (!(d = (char*)malloc(sizeof(char))))
		return (NULL);
	d[0] = '\0';
	return (d);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	count;
	size_t	len;
	size_t	i;
	char	*d;

	d = NULL;
	if (s1 == NULL || set == NULL)
		return (NULL);
	len = ft_strlen((char*)s1);
	i = -1;
	count = 0;
	while (ft_contain_set(s1[len - ++i - 1], (char*)set))
		if (++count == len)
			return (ft_return_blank(d));
	s1--;
	while (ft_contain_set(*++s1, (char*)set))
		count++;
	len = len - count;
	if (!(d = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = -1;
	while (len - ++i)
		d[i] = s1[i];
	d[i] = '\0';
	return (d);
}
