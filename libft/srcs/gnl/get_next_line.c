/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:52:09 by gvenet            #+#    #+#             */
/*   Updated: 2021/02/09 11:19:03 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char		*ft_get_current_line(char *mem)
{
	int		i;
	int		l_len;
	char	*line;

	i = -1;
	l_len = 0;
	if (mem == NULL)
		return (NULL);
	while (mem[l_len] != '\n' && mem[l_len] != '\0')
		l_len++;
	if (!(line = (char *)malloc(sizeof(char) * (l_len + 1))))
		return (NULL);
	while (mem[++i] != '\n' && mem[i] != '\0')
		line[i] = mem[i];
	line[i] = '\0';
	return (line);
}

char		*ft_get_new_mem(char *mem)
{
	int		i;
	char	*ret;
	char	*p_mem;

	p_mem = mem;
	if (mem == NULL)
		return (NULL);
	while (*p_mem != '\n' && *p_mem != '\0')
		p_mem++;
	if (!(ret = (char *)malloc(sizeof(char) * (ft_strlen_gnl(p_mem) + 1))))
	{
		free(mem);
		return (NULL);
	}
	if (*p_mem == '\n')
		p_mem++;
	i = 0;
	while (*p_mem != '\0')
		ret[i++] = *p_mem++;
	ret[i] = '\0';
	free(mem);
	return (ret);
}

int			ft_contains_n(char *s)
{
	int		i;

	i = -1;
	if (s == NULL)
		return (-1);
	while (s[++i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
	}
	return (0);
}

int			get_next_line(int fd, char **line)
{
	char			buf[BUFFER_SIZE + 1];
	static char		*mem;
	int				read_size;

	read_size = 1;
	if ((fd == -1 || line == NULL || read(fd, buf, 0) == -1) || !BUFFER_SIZE)
		return (-1);
	if (!mem)
	{
		if (!(mem = (char*)malloc(sizeof(char))))
			return (-1);
		*mem = '\0';
	}
	while (ft_contains_n(mem) == 0 && read_size != 0)
	{
		if ((read_size = read(fd, buf, BUFFER_SIZE)) == -1)
			return (-1);
		buf[read_size] = '\0';
		mem = ft_strjoin_gnl(mem, buf);
	}
	*line = ft_get_current_line(mem);
	mem = ft_get_new_mem(mem);
	return (return_value(&mem, *line, read_size));
}

int			return_value(char **mem, char *line, int read_size)
{
	if (*mem == NULL || line == NULL)
		return (exit_freed(&(*mem), -1));
	if (read_size == 0)
		return (exit_freed(&(*mem), 0));
	return (1);
}
