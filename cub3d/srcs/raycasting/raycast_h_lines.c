/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_h_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:09:17 by gvenet            #+#    #+#             */
/*   Updated: 2021/02/26 12:21:36 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	raycast_algo_h_lines(t_data *d, t_rays *r, t_player *p, t_map *m)
{
	limits(r, p, m);
	r->mx = (int)r->x;
	r->my = (int)r->y;
	r->h_x = r->x;
	r->h_y = r->y;
	if (m->matrix[r->my][r->mx] == 1 || m->matrix[r->my][r->mx] == 9)
	{
		r->mh = m->matrix[r->my][r->mx];
		r->h_dist = sqrt(((r->h_x - p->x) * (r->h_x - p->x)) + \
		((r->h_y - p->y) * (r->h_y - p->y)));
		r->dof = r->dof_limit;
	}
	else
	{
		r->x += r->xo;
		r->y += r->yo;
		if (m->matrix[r->my][r->mx] == 2)
			check_sprite_screen_h(d, m, &(d->s), r);
		r->dof++;
	}
}

void	check_h_lines(t_data *d, t_rays *r, t_player *p, t_map *m)
{
	r->dof = 0;
	r->h_tan = -1 / tan(r->a);
	if (r->a > M_PI)
	{
		r->y = floor(p->y) - 0.00001;
		r->x = (p->y - r->y) * r->h_tan + p->x;
		r->yo = -1;
		r->xo = -r->yo * r->h_tan;
	}
	if (r->a < M_PI)
	{
		r->y = ceil(p->y);
		r->x = (p->y - r->y) * r->h_tan + p->x;
		r->yo = 1;
		r->xo = -r->yo * r->h_tan;
	}
	while (r->dof < r->dof_limit)
		raycast_algo_h_lines(d, r, p, m);
}
