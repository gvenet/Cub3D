/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 14:20:13 by gvenet            #+#    #+#             */
/*   Updated: 2021/03/01 14:14:52 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	draw_walls_background(t_data *d, t_walls *w)
{
	int	i;
	int	j;
	int c;

	j = -1;
	while (++j < d->win.y)
	{
		i = -1;
		while (++i < d->win.x)
		{
			if (j < d->win.y / 2)
				c = create_color(0, w->ceil.r, w->ceil.g, w->ceil.b);
			else
				c = create_color(0, w->floor.r, w->floor.g, w->floor.b);
			pixel_put(&(d->img), i, j, c);
		}
	}
}

void	draw_texture_step(t_data *d, t_texture t, t_rays *r, t_walls *w)
{
	int	x;
	int	y;

	y = w->line_o;
	while (++y < w->line_o + w->line_h)
	{
		w->color = t.addr[((int)(w->ty) * (t.w)) + ((int)(w->tx))];
		t.c.r = get_r(w->color);
		t.c.g = get_g(w->color);
		t.c.b = get_b(w->color);
		w->color = create_color(0, t.c.r * w->sh, t.c.g * w->sh, t.c.b * w->sh);
		x = (r->r * (d->win.x / (d->win.x / r->r_div)));
		while (x < (r->r * (d->win.x / (d->win.x / r->r_div))) + \
		(d->win.x / (d->win.x / r->r_div)))
		{
			pixel_put(&(d->img), x, y, w->color);
			x++;
		}
		w->ty += w->ty_step;
	}
}

void	draw_texture(t_data *d, t_texture t, t_rays *r, t_walls *w)
{
	w->ty = w->ty_off * w->ty_step;
	if (r->v_dist > r->h_dist)
	{
		w->tx = (int)(r->x * t.w) % t.w;
		if (r->a < M_PI)
			w->tx = t.w - w->tx;
	}
	else
	{
		w->tx = (int)(r->y * t.h) % t.h;
		if (r->a > P2 && r->a < P3)
			w->tx = t.w - w->tx;
	}
	draw_texture_step(d, t, r, w);
}

void	draw_walls(t_data *d, t_rays *r, t_walls *w)
{
	w->ca = d->p.a - r->a;
	if (w->ca < 0)
		w->ca += 2 * M_PI;
	if (w->ca > 2 * M_PI)
		w->ca -= 2 * M_PI;
	r->dist = r->dist * cos(w->ca);
	w->line_h = (d->win.y * 2 / r->dist);
	w->ty_step = 64 / (float)w->line_h;
	w->ty_off = 0;
	w->line_o = (d->win.y / 2) - w->line_h / 2;
	if (w->line_h > d->win.y)
	{
		w->ty_off = (w->line_h - d->win.y) / 2;
		w->line_h = d->win.y;
		w->line_o = 0;
	}
	if ((r->v_dist > r->h_dist) && r->mh == 1 && r->a > M_PI)
		draw_texture(d, d->n_tex, r, w);
	else if ((r->v_dist > r->h_dist) && r->mh == 1 && r->a < M_PI)
		draw_texture(d, d->s_tex, r, w);
	else if ((r->v_dist < r->h_dist) && r->mv == 1 && (r->a > P2 && r->a < P3))
		draw_texture(d, d->w_tex, r, w);
	else if ((r->v_dist < r->h_dist) && r->mv == 1 && (r->a < P2 || r->a > P3))
		draw_texture(d, d->e_tex, r, w);
}
