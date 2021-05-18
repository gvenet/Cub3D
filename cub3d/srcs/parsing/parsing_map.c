/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:26:01 by gvenet            #+#    #+#             */
/*   Updated: 2021/03/01 10:43:43 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	xy_count(char *av, char *line, t_map *m, t_data *d)
{
	int fd;
	int ret;
	int cnt;

	cnt = 0;
	m->y = 0;
	m->x = 0;
	ret = 1;
	fd = open(av, O_RDONLY);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		check_line_map(line, d, &cnt);
		if (is_map(line))
		{
			m->y++;
			if (m->x < (int)ft_strlen(line))
				m->x = ft_strlen(line);
		}
		free(line);
	}
	close(fd);
}

static void	malloc_map(t_data *d, t_map *m)
{
	int y;
	int x;

	if (!(m->matrix = (int**)malloc(m->y * sizeof(int*))))
		leave(d);
	y = -1;
	while (++y < m->y)
	{
		if (!(m->matrix[y] = (int*)malloc(m->x * sizeof(int))))
			leave(d);
		x = -1;
		while (++x < m->x)
			m->matrix[y][x] = 9;
	}
}

static void	fill_map_bis(t_data *d, char *l, int x, int y)
{
	if (l[x] == 'N' || l[x] == 'S' || \
	l[x] == 'E' || l[x] == 'W')
	{
		d->p.nb_cam++;
		d->map.matrix[y][x] = 0;
		d->p.x = x + 0.5;
		d->p.y = y + 0.5;
		if (l[x] == 'N')
			d->p.a = 3 * M_PI / 2;
		else if (l[x] == 'S')
			d->p.a = M_PI / 2;
		else if (l[x] == 'E')
			d->p.a = 0;
		else if (l[x] == 'W')
			d->p.a = M_PI;
	}
	else if (l[x] == ' ')
		d->map.matrix[y][x] = 9;
	else
	{
		d->map.matrix[y][x] = l[x] - '0';
		if (d->map.matrix[y][x] == 2)
			d->s.count++;
	}
	wrong_symbol_map(l, d, x);
}

static void	fill_map(char *av, char *line, t_data *d)
{
	int fd;
	int y;
	int x;
	int ret;

	fd = open(av, O_RDONLY);
	y = 0;
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (is_map(line))
		{
			x = -1;
			while (line[++x])
				fill_map_bis(d, line, x, y);
			y++;
		}
		free(line);
	}
	close(fd);
}

void		parse_map(t_data *d, char *av)
{
	char *line;

	line = NULL;
	xy_count(av, line, &(d->map), d);
	malloc_map(d, &(d->map));
	fill_map(av, line, d);
	mapdup(d, &(d->map));
	flood_fill_check(d, (int)d->p.x, (int)d->p.y);
}
