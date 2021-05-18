/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 12:30:26 by gvenet            #+#    #+#             */
/*   Updated: 2021/02/26 12:21:24 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	parse_resolution(t_data *d, char *format)
{
	if (d->win.resolution != NULL)
		leave(d);
	d->valid_line = 1;
	format++;
	while (!ft_isdigit(*format))
		if (*format++ != ' ')
			leave(d);
	d->win.resolution = ft_split(format, ' ');
	d->win.er = -1;
	while (d->win.resolution[++d->win.er])
		;
	if (d->win.er != 2)
		leave(d);
	d->win.er = 2;
	test_res(d);
	d->win.x = ft_atoi(d->win.resolution[0]);
	d->win.y = ft_atoi(d->win.resolution[1]);
	if (d->win.x > 2560)
		d->win.x = 2560;
	else if (d->win.x == 0)
		leave(d);
	if (d->win.y > 1395)
		d->win.y = 1395;
	else if (d->win.y == 0)
		leave(d);
}

void	parse_tex(char *format, t_data *d, t_texture *tex)
{
	int		i;
	int		fd;

	if (tex->path != NULL)
		leave(d);
	d->valid_line = 1;
	format += 2;
	while (*format == ' ')
		format++;
	i = -1;
	while (format[++i])
		;
	if (!(tex->path = (char*)malloc(sizeof(char) * (i + 1))))
		leave(d);
	i = 0;
	while (*format)
		tex->path[i++] = *format++;
	tex->path[i] = '\0';
	fd = 0;
	if (!(fd == open(tex->path, O_RDONLY) < 0))
		leave(d);
	close(fd);
}

void	parse_color(char *format, t_color *c, t_data *d)
{
	if (c->rgb != NULL)
		leave(d);
	d->valid_line = 1;
	format++;
	while (!ft_isdigit(*format))
		if (*format++ != ' ')
			leave(d);
	while (*format == ' ')
		format++;
	c->rgb = ft_split(format, ',');
	c->er = -1;
	while (c->rgb[++c->er])
		;
	if (c->er != 3)
		leave(d);
	d->win.er = 3;
	wrong_nb_colors(format, c, d);
	c->r = ft_atoi(c->rgb[0]);
	c->g = ft_atoi(c->rgb[1]);
	c->b = ft_atoi(c->rgb[2]);
	if (c->r < 0 || c->r > 255 || c->g < 0 || c->g > 255 \
	|| c->b < 0 || c->b > 255)
		leave(d);
}

void	parse_param_bis(t_data *d, char *line)
{
	char *format;

	format = line;
	while (*format == ' ')
		format++;
	if (format[0] == 'R')
		parse_resolution(d, format);
	else if (format[0] == 'N' && format[1] == 'O')
		parse_tex(format, d, &(d->n_tex));
	else if (format[0] == 'S' && format[1] == 'O')
		parse_tex(format, d, &(d->s_tex));
	else if (format[0] == 'W' && format[1] == 'E')
		parse_tex(format, d, &(d->w_tex));
	else if (format[0] == 'E' && format[1] == 'A')
		parse_tex(format, d, &(d->e_tex));
	else if (format[0] == 'S' && format[1] == ' ')
		parse_tex(format, d, &(d->s));
	else if (format[0] == 'F')
		parse_color(format, &(d->w.floor), d);
	else if (format[0] == 'C')
		parse_color(format, &(d->w.ceil), d);
	if (d->valid_line == 0)
		leave(d);
}

void	parse_param(t_data *d, char *av)
{
	int		fd;
	char	*line;
	int		ret;

	ret = 1;
	line = NULL;
	if (!ft_charchr(av, '.'))
		leave(d);
	if ((fd = open(av, O_RDONLY)) < 0 \
	|| ft_strcmp(ft_strrchr(av, '.'), ".cub"))
		leave(d);
	while (ret > 0)
	{
		d->valid_line = 0;
		if ((ret = get_next_line(fd, &line)) < 0)
			leave(d);
		if (!is_map(line) && !is_empty(line))
			parse_param_bis(d, line);
		free(line);
	}
	close(fd);
}
