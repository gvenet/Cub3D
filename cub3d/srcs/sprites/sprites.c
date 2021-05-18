/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 10:41:36 by gvenet            #+#    #+#             */
/*   Updated: 2021/02/26 12:21:56 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	get_sp_h(t_coor *s, t_rays *r, t_player *p)
{
	t_coor	i;
	t_coor	j;
	float	m;
	float	k;
	float	div;

	i.x = s->sx1 - s->sx0;
	i.y = s->sy1 - s->sy0;
	j.x = r->x - p->x;
	j.y = r->y - p->y;
	m = 0;
	k = 0;
	div = i.x * j.y - i.y * j.x;
	if (div != 0)
	{
		m = (i.x * s->sy0 - i.x * p->y - i.y * s->sx0 + i.y * p->x) / div;
		k = (j.x * s->sy0 - j.x * p->y - j.y * s->sx0 + j.y * p->x) / div;
	}
	if (m >= 0 && m <= 1 && k >= 0 && k <= 1)
	{
		s->h_px = p->x + m * j.x;
		s->h_py = p->y + m * j.y;
		s->h_draw = true;
	}
}

void	get_sp_v(t_coor *s, t_rays *r, t_player *p)
{
	t_coor	i;
	t_coor	j;
	float	m;
	float	k;
	float	div;

	i.x = s->sx1 - s->sx0;
	i.y = s->sy1 - s->sy0;
	j.x = r->x - p->x;
	j.y = r->y - p->y;
	m = 0;
	k = 0;
	div = i.x * j.y - i.y * j.x;
	if (div != 0)
	{
		m = (i.x * s->sy0 - i.x * p->y - i.y * s->sx0 + i.y * p->x) / div;
		k = (j.x * s->sy0 - j.x * p->y - j.y * s->sx0 + j.y * p->x) / div;
	}
	if (m >= 0 && m <= 1 && k >= 0 && k <= 1)
	{
		s->v_px = p->x + m * j.x;
		s->v_py = p->y + m * j.y;
		s->v_draw = true;
	}
}

void	check_sprite_screen_h(t_data *d, t_map *m, t_texture *s, t_rays *r)
{
	int i;

	i = -1;
	while (++i < s->count)
	{
		if (m->matrix[r->my][r->mx] == 2)
			get_sp_h(&(s->tab[i]), r, &(d->p));
		if (s->tab[i].h_draw == true)
		{
			s->tab[i].px = s->tab[i].h_px;
			s->tab[i].py = s->tab[i].h_py;
		}
	}
}

void	check_sprite_screen_v(t_data *d, t_map *m, t_texture *s, t_rays *r)
{
	int i;

	i = -1;
	while (++i < s->count)
	{
		if (m->matrix[r->my][r->mx] == 2)
			get_sp_v(&(s->tab[i]), r, &(d->p));
		if (s->tab[i].v_draw == true)
		{
			s->tab[i].px = s->tab[i].v_px;
			s->tab[i].py = s->tab[i].v_py;
		}
	}
}
