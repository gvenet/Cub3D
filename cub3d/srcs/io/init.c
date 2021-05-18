/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 14:30:14 by gvenet            #+#    #+#             */
/*   Updated: 2021/03/01 14:23:30 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	player_init(t_player *p, t_map *m)
{
	p->dx = cos(p->a);
	p->dy = sin(p->a);
	p->move_speed = 0.15;
	p->rotate_speed = 0.06;
	m->b_size = 8;
}

void	rays_init(t_data *d)
{
	d->r.a = d->p.a;
	d->p.fov = 60;
	if (d->map.x > d->map.y)
		d->r.dof_limit = d->map.x;
	else
		d->r.dof_limit = d->map.y;
	if (d->win.x <= 751)
		d->r.r_div = 2;
	else if (d->win.x <= 1001)
		d->r.r_div = 4;
	else if (d->win.x <= 1401)
		d->r.r_div = 8;
	else
		d->r.r_div = 16;
}

void	map_init(t_data *d, char *av)
{
	d->s.count = 0;
	parse_map(d, av);
	camera_errors(d, &(d->map));
	d->map.w_map.x = d->map.x * d->map.b_size;
	d->map.w_map.y = d->map.y * d->map.b_size;
}

void	sprite_init(t_data *d, t_map *map, t_texture *s)
{
	int i;
	int x;
	int y;

	if (!(s->tab = (t_coor*)malloc(sizeof(t_coor) * s->count)))
		leave(d);
	i = 0;
	y = -1;
	while (++y < map->y)
	{
		x = -1;
		while (++x < map->x)
		{
			if (map->matrix[y][x] == 2)
			{
				s->tab[i].x = x + 0.5;
				s->tab[i].y = y + 0.5;
				s->tab[i].id = i + 1;
				i++;
			}
		}
	}
}

void	data_init(t_data *d, char *av)
{
	d->mlx = mlx_init();
	parse_param(d, av);
	load_textures(d);
	map_init(d, av);
	player_init(&(d->p), &(d->map));
	sprite_init(d, &(d->map), &(d->s));
	rays_init(d);
	alloc_var_test(d);
	if (d->save.save == false)
	{
		d->win.win = mlx_new_window(d->mlx, d->win.x, d->win.y, "cub3d");
		d->map.w_map.win = mlx_new_window(d->mlx, d->map.x * d->map.b_size, \
		d->map.y * d->map.b_size, "minimap");
	}
}
