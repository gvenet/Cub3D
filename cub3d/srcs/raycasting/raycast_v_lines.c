/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_v_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:09:55 by gvenet            #+#    #+#             */
/*   Updated: 2021/02/26 12:21:38 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	raycast_algo_v_lines(t_data *d, t_rays *r, t_player *p, t_map *m)
{
	limits(r, p, m);
	r->mx = (int)r->x;
	r->my = (int)r->y;
	r->v_x = r->x;
	r->v_y = r->y;
	if (m->matrix[r->my][r->mx] == 1 || m->matrix[r->my][r->mx] == 9)
	{
		r->mv = m->matrix[r->my][r->mx];
		r->v_dist = sqrt(((r->v_x - p->x) * (r->v_x - p->x)) + \
		((r->v_y - p->y) * (r->v_y - p->y)));
		r->dof = r->dof_limit;
	}
	else
	{
		r->x += r->xo;
		r->y += r->yo;
		if (m->matrix[r->my][r->mx] == 2)
			check_sprite_screen_v(d, m, &(d->s), r);
		r->dof++;
	}
}

void	check_v_lines(t_data *d, t_rays *r, t_player *p, t_map *m)
{
	r->dof = 0;
	r->v_tan = -tan(r->a);
	if (r->a > P2 && r->a < P3)
	{
		r->x = floor(p->x) - 0.00001;
		r->y = (p->x - r->x) * r->v_tan + p->y;
		r->xo = -1;
		r->yo = -r->xo * r->v_tan;
	}
	if (r->a < P2 || r->a > P3)
	{
		r->x = ceil(p->x);
		r->y = (p->x - r->x) * r->v_tan + p->y;
		r->xo = 1;
		r->yo = -r->xo * r->v_tan;
	}
	while (r->dof < r->dof_limit)
		raycast_algo_v_lines(d, r, p, m);
}
