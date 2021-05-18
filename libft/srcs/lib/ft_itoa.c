/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:22:06 by gvenet            #+#    #+#             */
/*   Updated: 2021/02/09 11:09:34 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int			ft_intlen(int n)
{
	int				len;
	long long int	nl;

	nl = n;
	len = 1;
	if (nl < 0)
	{
		nl *= -1;
		len++;
	}
	while (nl > 9)
	{
		nl /= 10;
		len++;
	}
	return (len);
}

static void			ft_strrev(char *str)
{
	char	tmp;
	size_t	i;
	size_t	j;

	i = -1;
	j = ft_strlen(str);
	while (++i < --j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
}

char				*ft_itoa(int n)
{
	char			*s;
	int				len;
	int				i;
	int				neg;
	long long int	nl;

	nl = n;
	len = ft_intlen(n);
	if (!(s = (char*)ft_calloc(((len + 1) * sizeof(char)), 1)))
		return (NULL);
	neg = (nl < 0 ? 1 : 0);
	i = -1;
	if (neg)
		nl *= -1;
	while (++i < len)
	{
		s[i] = (nl % 10) + '0';
		nl /= 10;
	}
	ft_strrev(s);
	if (neg)
		*s = '-';
	return (s);
}
