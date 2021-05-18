/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 07:32:04 by gvenet            #+#    #+#             */
/*   Updated: 2021/02/26 16:06:21 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	a_moves(t_data *d)
{
	if (d->mov.a == 1)
	{
		if (d->map.matrix[(int)(d->p.y)][(int)(d->p.x + d->p.dy / 2)] == 0)
			d->p.x += d->p.dy * d->p.move_speed;
		if (d->map.matrix[(int)(d->p.y - d->p.dx / 2)][(int)(d->p.x)] == 0)
			d->p.y -= d->p.dx * d->p.move_speed;
	}
}

void	w_moves(t_data *d)
{
	if (d->mov.w == 1)
	{
		if (d->map.matrix[(int)(d->p.y)][(int)(d->p.x + d->p.dx / 2)] == 0)
			d->p.x += d->p.dx * d->p.move_speed;
		if (d->map.matrix[(int)(d->p.y + d->p.dy / 2)][(int)(d->p.x)] == 0)
			d->p.y += d->p.dy * d->p.move_speed;
	}
}

void	s_moves(t_data *d)
{
	if (d->mov.s == 1)
	{
		if (d->map.matrix[(int)(d->p.y)][(int)(d->p.x - d->p.dx / 2)] == 0)
			d->p.x -= d->p.dx * d->p.move_speed;
		if (d->map.matrix[(int)(d->p.y - d->p.dy / 2)][(int)(d->p.x)] == 0)
			d->p.y -= d->p.dy * d->p.move_speed;
	}
}

void	d_moves(t_data *d)
{
	if (d->mov.d == 1)
	{
		if (d->map.matrix[(int)(d->p.y)][(int)(d->p.x - d->p.dy / 2)] == 0)
			d->p.x -= d->p.dy * d->p.move_speed;
		if (d->map.matrix[(int)(d->p.y + d->p.dx / 2)][(int)(d->p.x)] == 0)
			d->p.y += d->p.dx * d->p.move_speed;
	}
}

void	arrows_moves(t_data *d)
{
	if (d->mov.al == 1)
	{
		d->p.a -= d->p.rotate_speed;
		if (d->p.a < 0)
			d->p.a += 2 * M_PI;
		d->p.dx = cos(d->p.a);
		d->p.dy = sin(d->p.a);
	}
	if (d->mov.ar == 1)
	{
		d->p.a += d->p.rotate_speed;
		if (d->p.a > 2 * M_PI)
			d->p.a -= 2 * M_PI;
		d->p.dx = cos(d->p.a);
		d->p.dy = sin(d->p.a);
	}
}
