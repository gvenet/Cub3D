/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 14:28:06 by gvenet            #+#    #+#             */
/*   Updated: 2021/02/26 12:21:00 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int		key_release(int keycode, t_data *d)
{
	if (keycode == KEY_W)
		d->mov.w = 0;
	if (keycode == KEY_S)
		d->mov.s = 0;
	if (keycode == KEY_A)
		d->mov.a = 0;
	if (keycode == KEY_D)
		d->mov.d = 0;
	if (keycode == KEY_AL)
		d->mov.al = 0;
	if (keycode == KEY_AR)
		d->mov.ar = 0;
	return (0);
}

int		key_presse(int keycode, t_data *d)
{
	if (keycode == KEY_ESC)
	{
		d->error = 0;
		leave(d);
	}
	if (keycode == KEY_W)
		d->mov.w = 1;
	if (keycode == KEY_S)
		d->mov.s = 1;
	if (keycode == KEY_A)
		d->mov.a = 1;
	if (keycode == KEY_D)
		d->mov.d = 1;
	if (keycode == KEY_AL)
		d->mov.al = 1;
	if (keycode == KEY_AR)
		d->mov.ar = 1;
	return (0);
}

int		move_player(t_data *d)
{
	a_moves(d);
	w_moves(d);
	s_moves(d);
	d_moves(d);
	arrows_moves(d);
	render(d);
	return (0);
}

int		red_cross(t_data *d)
{
	d->error = 0;
	leave(d);
	return (0);
}
