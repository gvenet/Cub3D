/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:21:00 by gvenet            #+#    #+#             */
/*   Updated: 2021/03/01 10:51:58 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void		pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->l_size + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void		draw_line(t_img *img, t_data *d, t_bresenham_line pts, int color)
{
	pts.x0 = d->p.x * d->map.b_size;
	pts.y0 = d->p.y * d->map.b_size;
	pts.dx = abs(pts.x1 - pts.x0);
	pts.sx = pts.x0 < pts.x1 ? 1 : -1;
	pts.dy = -abs(pts.y1 - pts.y0);
	pts.sy = pts.y0 < pts.y1 ? 1 : -1;
	pts.err = pts.dx + pts.dy;
	while (1)
	{
		pixel_put(img, pts.x0, pts.y0, color);
		if (pts.x0 == pts.x1 && pts.y0 == pts.y1)
			break ;
		pts.e2 = 2 * pts.err;
		if (pts.e2 >= pts.dy)
		{
			pts.err += pts.dy;
			pts.x0 += pts.sx;
		}
		if (pts.e2 <= pts.dx)
		{
			pts.err += pts.dx;
			pts.y0 += pts.sy;
		}
	}
}

static void	check_zero_out(t_data *d, int x, int y, t_map *m)
{
	if (x - 1 < 0 || y - 1 < 0 || m->pars[y - 1][x - 1] == 9)
		leave(d);
	else if (x - 1 < 0 || m->pars[y - 1][x] == 9)
		leave(d);
	else if (x - 1 < 0 || y + 1 == m->y || m->pars[y - 1][x + 1] == 9)
		leave(d);
	else if (y - 1 < 0 || m->pars[y][x - 1] == 9)
		leave(d);
	else if (y + 1 == m->y || m->pars[y][x + 1] == 9)
		leave(d);
	else if (x + 1 == m->x || y - 1 < 0 || m->pars[y + 1][x - 1] == 9)
		leave(d);
	else if (x + 1 == m->x || m->pars[y + 1][x] == 9)
		leave(d);
	else if (x + 1 == m->x || y + 1 == m->y || m->pars[y + 1][x + 1] == 9)
		leave(d);
}

void		mapdup(t_data *d, t_map *m)
{
	int y;
	int x;

	if (!(m->pars = (int**)malloc(m->y * sizeof(int*))))
		leave(d);
	y = -1;
	while (++y < m->y)
	{
		if (!(m->pars[y] = (int*)malloc(m->x * sizeof(int))))
			leave(d);
		x = -1;
		while (++x < m->x)
			m->pars[y][x] = m->matrix[y][x];
	}
	y = -1;
	while (++y < m->y)
	{
		x = -1;
		while (++x < m->x)
			if (m->pars[y][x] == 0)
				check_zero_out(d, x, y, &(d->map));
	}
}

void		display_map(int **m, int x, int y)
{
	int i;
	int j;

	j = -1;
	while (++j < y)
	{
		i = -1;
		while (++i < x)
			ft_printf("%d", m[j][i]);
		ft_printf("\n");
	}
}
