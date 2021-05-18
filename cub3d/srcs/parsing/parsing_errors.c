/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 12:33:42 by gvenet            #+#    #+#             */
/*   Updated: 2021/02/26 12:21:15 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	camera_errors(t_data *d, t_map *m)
{
	int x;
	int y;

	x = (int)d->p.x;
	y = (int)d->p.y;
	if (d->p.nb_cam == 0)
		leave(d);
	if (d->p.nb_cam > 1)
		leave(d);
	if (x == m->x - 1 || x == 0 || y == m->y - 1 || y == 0 || \
	m->matrix[y][x + 1] == 9 || m->matrix[y][x - 1] == 9 || \
	m->matrix[y - 1][x] == 9 || m->matrix[y + 1][x] == 9)
		leave(d);
}

void	flood_fill_check(t_data *d, int x, int y)
{
	if (x < 0 || x >= d->map.x || y < 0 || y >= d->map.y)
		leave(d);
	if (d->map.pars[y][x] == 1)
		return ;
	if (d->map.pars[y][x] == 9)
		leave(d);
	if (d->map.pars[y][x] == 3)
		return ;
	d->map.pars[y][x] = 3;
	flood_fill_check(d, x + 1, y + 1);
	flood_fill_check(d, x - 1, y - 1);
	flood_fill_check(d, x - 1, y + 1);
	flood_fill_check(d, x + 1, y - 1);
	flood_fill_check(d, x + 1, y);
	flood_fill_check(d, x - 1, y);
	flood_fill_check(d, x, y + 1);
	flood_fill_check(d, x, y - 1);
}

void	wrong_symbol_map(char *l, t_data *d, int x)
{
	if (l[x] != '0' && l[x] != '1' && l[x] != '2' && l[x] != ' '\
	&& l[x] != 'N' && l[x] != 'S' && l[x] != 'E' && l[x] != 'W')
		leave(d);
}

void	wrong_nb_colors(char *format, t_color *c, t_data *d)
{
	int i;
	int j;

	i = -1;
	c->nb_color = 0;
	while (format[++i])
		if (format[i] == ',')
			c->nb_color++;
	if (c->nb_color != 2)
		leave(d);
	i = -1;
	while (++i < 3)
	{
		j = 0;
		while (c->rgb[i][j] == ' ')
			j++;
		while (ft_isdigit(c->rgb[i][j]))
			j++;
		while (c->rgb[i][j] == ' ')
			j++;
		if (c->rgb[i][j] != '\0')
			leave(d);
	}
}

void	check_line_map(char *line, t_data *d, int *cnt)
{
	if (*cnt > 0)
		if (is_map(line) || !is_empty(line))
			leave(d);
	if (!is_map(line) && !is_empty(line) && d->map.y != 0)
		leave(d);
	if (is_empty(line) && d->map.y != 0)
		*cnt += 1;
}
