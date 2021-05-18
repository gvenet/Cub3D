/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 09:49:52 by gvenet            #+#    #+#             */
/*   Updated: 2021/02/26 12:21:32 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	load_textures_ft(t_data *d, t_texture *tex)
{
	int		fd;
	char	buf[0];

	tex->w = 64;
	tex->h = 64;
	tex->s = tex->w * tex->h;
	if ((fd = open(tex->path, O_RDONLY)) < 0)
		leave(d);
	if (tex->path == NULL || read(fd, buf, 0) == -1)
		leave(d);
	close(fd);
	tex->img = mlx_new_image(d->mlx, tex->w, tex->h);
	tex->img = mlx_xpm_file_to_image(d->mlx, tex->path, &(tex->w), &(tex->h));
	tex->addr = (int*)mlx_get_data_addr(tex->img, &tex->bpp, \
	&(tex->l_size), &(tex->endian));
}

void	load_textures(t_data *d)
{
	load_textures_ft(d, &(d->n_tex));
	load_textures_ft(d, &(d->s_tex));
	load_textures_ft(d, &(d->e_tex));
	load_textures_ft(d, &(d->w_tex));
	load_textures_ft(d, &(d->s));
}
