/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 09:16:40 by gvenet            #+#    #+#             */
/*   Updated: 2021/02/26 12:22:06 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

unsigned char	*create_bitmap_file_header(int file_size)
{
	static unsigned char	file_header[14];

	ft_bzero(file_header, 14);
	file_header[0] = (unsigned char)('B');
	file_header[1] = (unsigned char)('M');
	file_header[2] = (unsigned char)(file_size);
	file_header[3] = (unsigned char)(file_size >> 8);
	file_header[4] = (unsigned char)(file_size >> 16);
	file_header[5] = (unsigned char)(file_size >> 24);
	file_header[10] = (unsigned char)(14 + 40);
	return (file_header);
}

unsigned char	*create_bitmap_info_header(t_data *d)
{
	static unsigned char info_header[40];

	ft_bzero(info_header, 40);
	info_header[0] = (unsigned char)(40);
	info_header[4] = (unsigned char)(d->win.x >> 0);
	info_header[5] = (unsigned char)(d->win.x >> 8);
	info_header[6] = (unsigned char)(d->win.x >> 16);
	info_header[7] = (unsigned char)(d->win.x >> 24);
	info_header[8] = (unsigned char)(d->win.y >> 0);
	info_header[9] = (unsigned char)(d->win.y >> 8);
	info_header[10] = (unsigned char)(d->win.y >> 16);
	info_header[11] = (unsigned char)(d->win.y >> 24);
	info_header[12] = (unsigned char)(1);
	info_header[14] = (unsigned char)(d->img.bpp);
	return (info_header);
}

void			write_img(int fd, t_data *d)
{
	int		x;
	int		y;

	x = -1;
	while (++x < d->win.y)
	{
		y = -1;
		while (++y < d->win.x)
			write(fd, d->save.addr + ((d->win.y - x - 1) *\
			d->img.l_size / (d->img.bpp / 8) + y), d->img.bpp / 8);
	}
}

void			create_bmp(const char *filename, t_data *d)
{
	int		fd;
	int		img_size;
	int		file_size;

	img_size = d->win.x * 4 * d->win.y;
	file_size = img_size + (40 + 14);
	close(open(filename, O_RDONLY | O_CREAT, S_IRWXU));
	fd = open(filename, O_RDWR);
	write(fd, create_bitmap_file_header(file_size), 14);
	write(fd, create_bitmap_info_header(d), 40);
	write_img(fd, d);
	close(fd);
	ft_printf("Image generated!!\n");
}
