/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 13:11:20 by gvenet            #+#    #+#             */
/*   Updated: 2021/03/01 13:28:19 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int		is_empty(char *line)
{
	int i;

	i = -1;
	while (line[++i] != '\0')
		if (line[i] == '1' || line[i] == '0' \
		|| ft_isalpha(line[i]))
			return (0);
	return (1);
}

int		is_map(char *line)
{
	int		i;
	char	*f;

	f = line;
	i = -1;
	while (*f == ' ')
		f++;
	while (*f != 'R' && *f != 'N' && *f != 'S' &&
	*f != 'W' && *f != 'E' &&
	*f != 'F' && *f != 'C' && f[++i])
		if (f[i] == '1')
			return (1);
	return (0);
}

void	alloc_var_init(t_data *d)
{
	d->img.img = NULL;
	d->map.img.img = NULL;
	d->s.tab = NULL;
	d->w.floor.rgb = NULL;
	d->w.ceil.rgb = NULL;
	d->n_tex.path = NULL;
	d->s_tex.path = NULL;
	d->w_tex.path = NULL;
	d->e_tex.path = NULL;
	d->s.path = NULL;
	d->win.resolution = NULL;
	d->map.matrix = NULL;
	d->map.pars = NULL;
}

void	alloc_var_test(t_data *d)
{
	if (d->s.tab == NULL || d->w.floor.rgb == NULL \
	|| d->w.ceil.rgb == NULL || d->n_tex.path == NULL \
	|| d->s_tex.path == NULL || d->w_tex.path == NULL \
	|| d->e_tex.path == NULL || d->s.path == NULL \
	|| d->win.resolution == NULL || d->map.matrix == NULL \
	|| d->map.pars == NULL)
		leave(d);
}

void	test_res(t_data *d)
{
	int i;
	int j;

	i = -1;
	while (d->win.resolution[++i])
	{
		j = -1;
		while (d->win.resolution[i][++j])
			if (!ft_isdigit(d->win.resolution[i][j]))
				leave(d);
	}
}
