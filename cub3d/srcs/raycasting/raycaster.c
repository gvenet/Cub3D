/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 14:46:39 by gvenet            #+#    #+#             */
/*   Updated: 2021/03/01 14:00:25 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	limits(t_rays *r, t_player *p, t_map *m)
{
	r->h_tan = -1 / tan(r->a);
	r->v_tan = -tan(r->a);
	if (r->x > m->x - 0.01)
	{
		r->x = (m->x - 0.01);
		r->y = (p->x - r->x) * r->v_tan + p->y;
	}
	if (r->x < 0.01)
	{
		r->x = 0.01;
		r->y = (p->x - r->x) * r->v_tan + p->y;
	}
	if (r->y > m->y - 0.01)
	{
		r->y = (m->y - 0.01);
		r->x = (p->y - r->y) * r->h_tan + p->x;
	}
	if (r->y < 0.01)
	{
		r->y = 0.01;
		r->x = (p->y - r->y) * r->h_tan + p->x;
	}
}

void	check_dist(t_rays *r, t_walls *w)
{
	if (r->v_dist < r->h_dist)
	{
		w->sh = 1;
		r->x = r->v_x;
		r->y = r->v_y;
		r->dist = r->v_dist;
	}
	if (r->v_dist > r->h_dist)
	{
		w->sh = 0.5;
		r->x = r->h_x;
		r->y = r->h_y;
		r->dist = r->h_dist;
	}
}

void	raycaster(t_data *d, t_rays *r, t_player *p, t_map *m)
{
	t_bresenham_line pts;

	r->r = -1;
	r->a = p->a - (DR / 2 * p->fov);
	sprite_minimap(&(d->s), &(d->p));
	while (++r->r < (float)d->win.x / r->r_div)
	{
		r->s_dist = 0;
		if (r->a < 0)
			r->a += 2 * M_PI;
		if (r->a > 2 * M_PI)
			r->a -= 2 * M_PI;
		check_h_lines(d, r, p, m);
		check_v_lines(d, r, p, m);
		check_dist(r, &(d->w));
		pts.x1 = r->x * m->b_size;
		pts.y1 = r->y * m->b_size;
		if (r->r == 0 || r->r == d->win.x / d->r.r_div - 1)
			draw_line(&(m->img), d, pts, 0x00FF0000);
		draw_walls(d, &(d->r), &(d->w));
		check_sprite_dist(d, &(d->s));
		r->a += DR / ((float)d->win.x / r->r_div / 60);
	}
}
