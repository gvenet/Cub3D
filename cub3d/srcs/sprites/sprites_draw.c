/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 07:44:06 by gvenet            #+#    #+#             */
/*   Updated: 2021/03/01 14:22:07 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	draw_sprite_step(t_data *d, t_rays *r, t_coor *sp, t_texture *s)
{
	int		x;
	int		y;
	float	sp_p;

	sp->ty = sp->ty_off * sp->ty_step;
	sp_p = sqrt((sp->sx0 - sp->px) * (sp->sx0 - sp->px) + \
	(sp->sy0 - sp->py) * (sp->sy0 - sp->py));
	sp->tx = (int)(sp_p * s->w) % s->w;
	y = sp->line_o + 1;
	while (++y < sp->line_o + sp->line_h)
	{
		sp->color = s->addr[((int)(sp->ty) * (s->w)) + ((int)(sp->tx))];
		x = (r->r * (d->win.x / (d->win.x / r->r_div)));
		while (x < (r->r * (d->win.x / (d->win.x / r->r_div))) + \
		(d->win.x / (d->win.x / r->r_div)))
		{
			if (sp->color != 0x00000000)
				pixel_put(&(d->img), x, y, sp->color);
			x++;
		}
		sp->ty += sp->ty_step;
	}
}

void	draw_sprite(t_data *d, t_rays *r, t_coor *sp, t_texture *s)
{
	sp->ca = d->p.a - r->a;
	if (sp->ca < 0)
		sp->ca += 2 * M_PI;
	if (sp->ca > 2 * M_PI)
		sp->ca -= 2 * M_PI;
	sp->dist = sp->dist * cos(sp->ca);
	sp->line_h = (d->win.y * 2 / sp->dist);
	sp->ty_step = 64 / (float)sp->line_h;
	sp->ty_off = 0;
	sp->line_o = (d->win.y / 2) - sp->line_h / 2;
	if (sp->line_h > d->win.y)
	{
		sp->ty_off = (sp->line_h - d->win.y) / 2;
		sp->line_h = d->win.y;
		sp->line_o = 0;
	}
	draw_sprite_step(d, r, sp, s);
}

void	check_sprite_dist(t_data *d, t_texture *s)
{
	int		i;
	t_coor	*sp;

	i = -1;
	while (++i < s->count)
	{
		sp = &(s->tab[i]);
		if (s->tab[i].h_draw == true || s->tab[i].v_draw == true)
		{
			sp->dist = sqrt(((sp->px - d->p.x) * (sp->px - d->p.x)) + \
			((sp->py - d->p.y) * (sp->py - d->p.y)));
			if (sp->dist < d->r.dist + 0.6)
				draw_sprite(d, &(d->r), sp, s);
		}
		sp->h_draw = false;
		sp->v_draw = false;
	}
}
