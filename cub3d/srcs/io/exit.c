/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:26:00 by gvenet            #+#    #+#             */
/*   Updated: 2021/02/26 14:47:20 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	tex_and_res_free(t_data *d)
{
	int i;

	if (d->n_tex.path)
		free(d->n_tex.path);
	if (d->s_tex.path)
		free(d->s_tex.path);
	if (d->w_tex.path)
		free(d->w_tex.path);
	if (d->e_tex.path)
		free(d->e_tex.path);
	if (d->s.path)
		free(d->s.path);
	if (d->s.tab)
		free(d->s.tab);
	if (d->win.resolution)
	{
		i = -1;
		while (++i < d->win.er)
			free(d->win.resolution[i]);
		free(d->win.resolution);
	}
}

static void	colors_free(t_data *d)
{
	int i;

	if (d->w.floor.rgb)
	{
		i = -1;
		while (++i < d->w.floor.er)
			free(d->w.floor.rgb[i]);
		free(d->w.floor.rgb);
	}
	if (d->w.ceil.rgb)
	{
		i = -1;
		while (++i < d->w.ceil.er)
			free(d->w.ceil.rgb[i]);
		free(d->w.ceil.rgb);
	}
}

static void	maps_free(t_data *d)
{
	int i;

	if (d->map.matrix)
	{
		i = -1;
		while (++i < d->map.y)
			if (d->map.matrix[i])
				free(d->map.matrix[i]);
		free(d->map.matrix);
	}
	if (d->map.pars)
	{
		i = -1;
		while (++i < d->map.y)
			if (d->map.pars[i])
				free(d->map.pars[i]);
		free(d->map.pars);
	}
}

void		leave(t_data *d)
{
	if (d->error)
		printf("\033[31mError\n\033[0m");
	tex_and_res_free(d);
	colors_free(d);
	maps_free(d);
	exit(0);
}
