/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 14:42:05 by gvenet            #+#    #+#             */
/*   Updated: 2021/03/01 14:27:45 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	minimap_drawcase(t_map *map, int i, int j, int color)
{
	int ip;
	int jp;

	ip = (i * map->b_size) - 1;
	while (++ip < (i * map->b_size) + map->b_size)
	{
		jp = (j * map->b_size) - 1;
		while (++jp < (j * map->b_size) + map->b_size)
			pixel_put(&(map->img), jp, ip, color);
	}
}

void	draw_minimap(t_map *map)
{
	int i;
	int j;
	int color;

	i = -1;
	while (++i < map->y)
	{
		j = -1;
		while (++j < map->x)
		{
			if (map->matrix[i][j] == 1)
				color = 0x00444444;
			else
				color = 0x00FFFFFF;
			minimap_drawcase(map, i, j, color);
		}
	}
}

void	draw_camera(t_map *m, t_player *p)
{
	float				x0;
	float				y0;
	float				p_size;

	p_size = m->b_size / 16;
	x0 = p->x * m->b_size - 1;
	while (++x0 < p->x * m->b_size + p_size)
	{
		y0 = p->y * m->b_size - 1;
		while (++y0 < p->y * m->b_size + p_size)
			pixel_put(&(m->img), x0 - p_size / 2,
			y0 - p_size / 2, 0x00FF0000);
	}
}

void	minimap(void *mlx, t_map *m, t_player *p, t_data *d)
{
	m->img.img = mlx_new_image(mlx, m->x * m->b_size, m->y * m->b_size);
	m->img.addr = mlx_get_data_addr(m->img.img, &m->img.bpp,
	&(m->img.l_size), &(m->img.endian));
	draw_minimap(m);
	d->img.img = mlx_new_image(d->mlx, d->win.x, d->win.y);
	d->img.addr = mlx_get_data_addr(d->img.img, &d->img.bpp,
	&(d->img.l_size), &(d->img.endian));
	draw_walls_background(d, &(d->w));
	raycaster(d, &(d->r), &(d->p), &(d->map));
	draw_camera(m, p);
	draw_minimap_sprites(m, &(d->s));
	if (d->save.save == false)
	{
		mlx_put_image_to_window(mlx, m->w_map.win, m->img.img, 0, 0);
		mlx_put_image_to_window(d->mlx, d->win.win, d->img.img, 0, 0);
	}
}
