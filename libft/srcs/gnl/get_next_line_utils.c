/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 08:28:45 by gvenet            #+#    #+#             */
/*   Updated: 2021/02/26 16:06:26 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char		*ft_strjoin_gnl(char *mem, char *buf)
{
	char	*ret;
	int		d_ret;
	int		i;

	d_ret = ft_strlen_gnl(mem) + ft_strlen_gnl(buf);
	if (!(ret = (char*)malloc(sizeof(char) * (d_ret + 1))))
	{
		free(mem);
		return (NULL);
	}
	i = -1;
	if (d_ret != 0)
	{
		while (++i < d_ret)
			ret[i] = '\0';
	}
	else
		*ret = '\0';
	ret = ft_strcpycat(ret, mem, buf, d_ret);
	free(mem);
	return (ret);
}

char		*ft_strcpycat(char *ret, char *mem, char *buf, int d_ret)
{
	int i;
	int j;

	i = -1;
	while (++i < d_ret && mem[i] != '\0')
		ret[i] = mem[i];
	ret[i] = '\0';
	j = 0;
	while (i < d_ret && buf[j] != '\0')
		ret[i++] = buf[j++];
	ret[i] = '\0';
	return (ret);
}

int			exit_freed(char **mem, int ret)
{
	if (*mem != NULL)
	{
		free(*mem);
		*mem = NULL;
	}
	return (ret);
}

int			ft_strlen_gnl(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
