/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 09:27:47 by gvenet            #+#    #+#             */
/*   Updated: 2021/02/26 12:21:51 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	draw_minimap_sprites(t_map *m, t_texture *s)
{
	int i;
	int j;
	int x;
	int y;

	j = -1;
	while (++j < m->y)
	{
		i = -1;
		while (++i < m->x)
		{
			y = -1;
			while (++y < m->b_size - 1 && m->matrix[j][i] == 2)
			{
				x = -1;
				while (++x < m->b_size - 1)
				{
					s->c.c = s->addr[(x + (y * 64)) * (64 / (int)m->b_size)];
					if (s->c.c != 0)
						pixel_put(&(m->img), x + (i * m->b_size), \
						y + (j * m->b_size), s->c.c);
				}
			}
		}
	}
}

void	pts_corr(t_texture *s, t_player *p, int i)
{
	if (s->tab[i].dy >= 0)
	{
		if (s->tab[i].dx >= 0)
			s->a = atan(s->tab[i].dy / s->tab[i].dx);
		else
			s->a = M_PI - atan(s->tab[i].dy / -s->tab[i].dx);
	}
	else if (s->tab[i].dy < 0)
	{
		if (s->tab[i].dx >= 0)
			s->a = 2 * M_PI + atan(s->tab[i].dy / s->tab[i].dx);
		else
			s->a = M_PI + atan(-s->tab[i].dy / -s->tab[i].dx);
	}
	s->f_min = p->a - M_PI / 6;
	s->f_max = p->a + M_PI / 6;
	s->tab[i].a = s->a;
	if (s->f_min < 0)
	{
		s->f_min += 2 * M_PI;
		s->f_max += 2 * M_PI;
	}
	if (s->f_max > 2 * M_PI && s->a < s->f_min)
		s->a += 2 * M_PI;
}

void	is_in_fov(t_texture *s, t_player *p)
{
	int					i;

	i = -1;
	while (++i < s->count)
	{
		s->tab[i].d = sqrt((p->x - s->tab[i].x) * (p->x - s->tab[i].x) \
		+ (p->y - s->tab[i].y) * (p->y - s->tab[i].y));
		s->tab[i].draw = false;
		s->tab[i].dx = s->tab[i].x - p->x;
		s->tab[i].dy = s->tab[i].y - p->y;
		pts_corr(s, p, i);
		if (s->a > s->f_min && s->a < s->f_max)
			s->tab[i].draw = true;
	}
}

void	sort_by_dist(t_texture *s)
{
	int		i;
	int		j;
	t_coor	tmp;

	i = -1;
	while (++i < s->count)
	{
		j = -1;
		while (++j < s->count - 1)
		{
			if (s->tab[j].d < s->tab[j + 1].d)
			{
				tmp = s->tab[j];
				s->tab[j] = s->tab[j + 1];
				s->tab[j + 1] = tmp;
			}
		}
	}
}

void	sprite_minimap(t_texture *s, t_player *p)
{
	int i;

	i = -1;
	is_in_fov(s, p);
	while (++i < s->count)
	{
		if (s->tab[i].draw == true)
		{
			s->tab[i].sx0 = s->tab[i].x + p->dy / 2;
			s->tab[i].sy0 = s->tab[i].y - p->dx / 2;
			s->tab[i].sx1 = s->tab[i].x - p->dy / 2;
			s->tab[i].sy1 = s->tab[i].y + p->dx / 2;
		}
	}
	sort_by_dist(s);
}
